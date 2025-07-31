#pragma once
// clang-format off

/*
    Anolex ESP32 Controller board

    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/

#define ILOVELIFE_4AXIS_WITH_PROBE_FLOOD

#ifdef ILOVELIFE_4AXIS_WITH_PROBE_FLOOD
#define MACHINE_NAME            "AnoleX - Axo"

#define X_STEP_PIN              GPIO_NUM_13
#define X_DIRECTION_PIN         GPIO_NUM_15
#define Y_STEP_PIN              GPIO_NUM_14
#define Y_DIRECTION_PIN         GPIO_NUM_27
#define Z_STEP_PIN              GPIO_NUM_26
#define Z_DIRECTION_PIN         GPIO_NUM_25
#define A_STEP_PIN              GPIO_NUM_33
#define A_DIRECTION_PIN         GPIO_NUM_32

#define X_LIMIT_PIN             GPIO_NUM_36
#define Y_LIMIT_PIN             GPIO_NUM_39
#define Z_LIMIT_PIN             GPIO_NUM_34
#define A_LIMIT_PIN             GPIO_NUM_4

// OK to comment out to use pin for other features
#define STEPPERS_DISABLE_PIN    GPIO_NUM_21

#define SPINDLE_TYPE            SpindleType::LASER
#define LASER_OUTPUT_PIN        SPINDLE_OUTPUT_PIN
#define SPINDLE_OUTPUT_PIN      GPIO_NUM_17   // labeled SpinPWM

#define SDCARD_DET_PIN          GPIO_NUM_35

#define MACRO_BUTTON_0_PIN      GPIO_NUM_2

#define COOLANT_FLOOD_PIN       GPIO_NUM_16  // labeled Flood
#define PROBE_PIN               GPIO_NUM_12  // labeled Probe

#define COOLANT_MIST_PIN GPIO_NUM_22

#define LIMITS_TWO_SWITCHES_ON_AXES

#endif