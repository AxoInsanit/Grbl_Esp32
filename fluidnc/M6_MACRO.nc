
;
;  M6T0 from T<anything> -- Resets the offsets for a new job;
;
;  M6T<not 0> From T0 --  Moves to the change location and does nothing else. Assumes work zero needs to be set
;
;  M6T<not 0> to T<anything> first time
;     -- Determines the TS offset
;     -- Goes to toolchange location
;     -- Set TLO
;     -- Returns to position before command;
;
;  M6T<not 0> to T<anything> after first time
;     -- Goes to toolchange location
;     -- Set TLO
;     -- Returns to position before command;
;
;  Possible New Persistent values (might want a save_ATC_values: config item. default false)
;     -- TLO
;     -- Tool number;
;
;
;  params:
;  safe_z_mm: Set this to the mpos height you want the Z to travel around when tool changing. It is typically near the top so the longest tool can clear the work.
;  change_mpos_mm_[]: This is where the machine will go for the manual tool change.;
;  ets_mpos_mm_[]: The X and Y location are the XY center of the toolsetter. The Z is the lowest the Z should go before we fail due to missing bit.;
;
;  You must set the current tool number with M61Q<number> in your macro
;  (print,foo is #<foo>, bar is %d#<bar>, fooint is %d#<foo>, bar2 is %.2f#<bar>, foo4 is %f#<foo>)

#<safe_z_mpos_mm> = -1.000
#<ets_rapid_z_mpos_mm> = -1.000
#<probe_seek_rate_mm_per_min> = 400.000
#<probe_feed_rate_mm_per_min> = 40.000
#<change_mpos_mm_x> = 280.000
#<change_mpos_mm_y> = -4.200
#<change_mpos_mm_z> = -1.000
#<ets_mpos_mm_x> = 220.003
#<ets_mpos_mm_y> = -4.200
#<ets_mpos_mm_z> = -40.000

(print, _current_tool is #<_current_tool>, _selected_tool is #<_selected_tool>, _have_tool_setter_offset is #<_have_tool_setter_offset>, _ets_tool1_z is #<_ets_tool1_z>)

;save modal state
#<initial_units> = #<_metric>; G20/G21

;save spindle state
#<initial_spindle_m> = #<_spindle_m>

;global vars set
o10 if [EXISTS[#<_have_tool_setter_offset>] EQ 0]
  #<_have_tool_setter_offset> = 0;
o10 endif

o20 if [EXISTS[#<_ets_tool1_z>] EQ 0]
  #<_ets_tool1_z> = 0;
o20 endif

G21 ; use metric for this macro

o100 if #<_plane> NEQ 170; Check G17 XY = 170
  (MSG: Only G17 is supported by this macro)
  $Send/Alarm=3; (Abort during cycle)
o100 elseif [#<_selected_tool> EQ 0]; M6T0 is used to reset this ATC and allow us to start a new job
 (MSG: M6T0 reset ATC)
 ;move to safe z
   G53G0Z[#<safe_z_mpos_mm>]
  M5; turn off spindle
 ;move to change location
   G53G0X[#<change_mpos_mm_x>]Y[#<change_mpos_mm_y>]Z[#<change_mpos_mm_z>]
 ;reset
   ;#<_prev_tool> = 0;
   #<_have_tool_setter_offset> = 0;
   M61Q[#<_selected_tool>]
   G43.1Z0 ;reset the TLO to 0
   (MSG: TLO Z reset to 0)
o100 elseif [#<_current_tool> EQ 0]; M6T<anything> from T0 is used for a manual change before zero'ing
  (MSG: M6T<anything> from T0)
  ;move to safe z
    G53G0Z[#<safe_z_mpos_mm>]
  M5; turn off spindle
  ;move to change location
    G53G0X[#<change_mpos_mm_x>]Y[#<change_mpos_mm_y>]Z[#<change_mpos_mm_z>]
    G4P0 0.1; execute all buffered gcode
    G43.1Z0; reset TLO to 0
    (MSG : Install tool #<_selected_tool>)
    ;#<_prev_tool> = #<_selected_tool>
  M61Q[#<_selected_tool>]
o100 else; M6T<anything> from not T0
 (MSG: M6T<anything> from <not>T0)
 ;save current location, so we can return after the tool change.
    #<start_x> = #<_abs_x>
    #<start_y> = #<_abs_y>
    #<start_z> = #<_abs_z>
 ;move to safe z
    G53G0Z[#<safe_z_mpos_mm>]
  M5; turn off spindle
  o200 if[#<_have_tool_setter_offset> EQ 0]; if we have not determined the tool setter offset yet, we need to do that.
     (MSG: _have_tool_setter_offset == 0)
     ;move over toolsetter
       G53G0Z[#<safe_z_mpos_mm>]; move to safe z
       G53G0X[#<ets_mpos_mm_x>]Y[#<ets_mpos_mm_y>]; move over toolsetter
     ;ets probe
       G53G0Z[#<ets_rapid_z_mpos_mm>]; rapid down
       G53 G38.2 Z[#<ets_mpos_mm_z>] F[#<probe_seek_rate_mm_per_min>]; seek
       G53G0Z[#<_abs_z> + 5]; retract before next probe
       G53 G38.2 Z[#<ets_mpos_mm_z>] F[#<probe_feed_rate_mm_per_min>]; do the feed rate probe
     #<_ets_tool1_z> = [#5063] ;save the value of the tool1 ETS Z
     #<_have_tool_setter_offset> = 1;
     ;move to safe z
       G53G0Z[#<safe_z_mpos_mm>]
  o200 endif

  ;move to change location
  G53G0X[#<change_mpos_mm_x>]Y[#<change_mpos_mm_y>]Z[#<change_mpos_mm_z>]
  G4P0 0.1; execute all buffered gcode
  (MSG: Install tool #<_selected_tool> then resume to continue)
  M0
  ;probe the new tool
  ;move over toolsetter
      G53G0Z[#<safe_z_mpos_mm>]; move to safe z
      G53G0X[#<ets_mpos_mm_x>]Y[#<ets_mpos_mm_y>]; move over toolsetter
  ;ets probe
       G53G0Z[#<ets_rapid_z_mpos_mm>]; rapid down
       G53 G38.2 Z[#<ets_mpos_mm_z>] F[#<probe_seek_rate_mm_per_min>]; seek
       G53G0Z[#<_abs_z> + 5]; retract before next probe
       G53 G38.2 Z[#<ets_mpos_mm_z>] F[#<probe_feed_rate_mm_per_min>]; do the feed rate probe
  #<my_tlo_z > = [#5063 - #<_ets_tool1_z>]; TLO is simply the difference between the tool1 probe and the new tool probe.
  G43.1Z#<my_tlo_z>
  ;move to safe z
    G53G0Z[#<safe_z_mpos_mm>]
  ;return to location before the tool change
  G53G0X#<start_x>Y#<start_y>
  G53G0Z#<start_z>
  ;#<_prev_tool> = #<_selected_tool>
  M61Q[#<_selected_tool>]; tool change sucessful
  ;M#<initial_spindle_m> ; set spindle to initial state
o100 endif

;restore modal state
G[20+#<initial_units>]; restore G20/G21
