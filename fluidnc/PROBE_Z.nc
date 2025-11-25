; dual speed probe macro

; reset modal state
G0 G54 G17 G21 G90 G94

; set Probing parameters
#<fast_rate>=160
#<slow_rate>=30
#<probe_dist>=10
#<probe_offset>=0.0194
#<retract_height>=1
;Coordinates of a G38 probe result (X, Y, Z, A, B, C, U, V & W).
;5061 X
;5062 Y
;5063 Z

(print, Z Probing: Make sure the probe is in the spindle then resume to continue)
M0

G38.2 G91 Z[-#<probe_dist>] F#<fast_rate> ; probe fast
G0 Z2  ; retract a little
G38.2 G91 Z[-2.5] F#<slow_rate>; probe slowly
#<mpos_touch>=#5063 ; save the z touch WCO location G54 (todo: make it work up to G59)
(G0 Z[#<retract_height>+#<probe_offset>] ; retract)
G10 L2 P0 Z[#<mpos_touch>+#<probe_offset>]
G91 G0 Z[#<retract_height>+#<probe_offset>]

; Restore modal state
G0 G54 G17 G21 G90 G94