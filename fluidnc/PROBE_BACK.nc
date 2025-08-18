; dual speed probe macro

; reset modal state
G0 G54 G17 G21 G90 G94

; set parameters
#<fast_rate>=160
#<slow_rate>=40
#<probe_dist>=40
#<probe_offset>=0.9335
#<retract_dist>=2

G38.2 G91 Y[-#<probe_dist>] F#<fast_rate> ; probe fast
G0 Y2  ; retract a little
G38.2 G91 Y[-#<probe_dist>] F#<slow_rate>; probe slowly
;Coordinates of a G38 probe result (X, Y, Z, A, B, C, U, V & W).
;5061 X
;5062 Y
;5063 Z
#<mpos_touch>=#5062 ; save the touch WCO location
;G0 Y[#<retract_dist>+#<probe_offset>] ; retract
G10 L2 P0 Y[#<mpos_touch>-#<probe_offset>]
G91 G0 Y[#<retract_dist>+#<probe_offset>]

; reset modal state
G0 G54 G17 G21 G90 G94