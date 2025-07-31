#pragma once
// clang-format off

/*
    3axis_v4.h
    Part of Grbl_ESP32

    Pin assignments for the ESP32 Development Controller, v4.1 and later.
    https://github.com/bdring/Grbl_ESP32_Development_Controller
    https://www.tindie.com/products/33366583/grbl_esp32-cnc-development-board-v35/

    2018    - Bart Dring
    2020    - Mitch Bradley

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

#ifdef ILOVELIFE_4AXIS
#define MACHINE_NAME            "ILoveLife 4axis"

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
#endif

#ifdef ILOVELIFE_3AXIS
#define MACHINE_NAME            "ILoveLife 3axis"

#define X_STEP_PIN              GPIO_NUM_13
#define X_DIRECTION_PIN         GPIO_NUM_15
#define Y_STEP_PIN              GPIO_NUM_14
#define Y_DIRECTION_PIN         GPIO_NUM_27
#define Z_STEP_PIN              GPIO_NUM_26
#define Z_DIRECTION_PIN         GPIO_NUM_25

#define X_LIMIT_PIN             GPIO_NUM_36
#define Y_LIMIT_PIN             GPIO_NUM_39
#define Z_LIMIT_PIN             GPIO_NUM_34

// OK to comment out to use pin for other features
#define STEPPERS_DISABLE_PIN    GPIO_NUM_21

#define SPINDLE_TYPE            SpindleType::LASER
#define LASER_OUTPUT_PIN        SPINDLE_OUTPUT_PIN
#define SPINDLE_OUTPUT_PIN      GPIO_NUM_17   // labeled SpinPWM

#define SDCARD_DET_PIN          GPIO_NUM_35

#define MACRO_BUTTON_0_PIN      GPIO_NUM_2
#endif

#ifdef ILOVELIFE_3AXIS_COREXY
#define CUSTOM_CODE_FILENAME    "../Custom/CoreXY.cpp"
#define MACHINE_NAME            "ILoveLife 3axis CoreXY"

#define X_STEP_PIN              GPIO_NUM_13
#define X_DIRECTION_PIN         GPIO_NUM_15
#define Y_STEP_PIN              GPIO_NUM_14
#define Y_DIRECTION_PIN         GPIO_NUM_27
#define Z_STEP_PIN              GPIO_NUM_26
#define Z_DIRECTION_PIN         GPIO_NUM_25

#define X_LIMIT_PIN             GPIO_NUM_36
#define Y_LIMIT_PIN             GPIO_NUM_39
#define Z_LIMIT_PIN             GPIO_NUM_34

// OK to comment out to use pin for other features
#define STEPPERS_DISABLE_PIN    GPIO_NUM_21

#define SPINDLE_TYPE            SpindleType::LASER
#define LASER_OUTPUT_PIN        SPINDLE_OUTPUT_PIN
#define SPINDLE_OUTPUT_PIN      GPIO_NUM_17   // labeled SpinPWM

#define SDCARD_DET_PIN          GPIO_NUM_35

#define MACRO_BUTTON_0_PIN      GPIO_NUM_2
#endif
#ifdef ILOVELIFE_3AXIS_DUALY
#define MACHINE_NAME            "ILoveLife 4axis dual Y"

#define X_STEP_PIN              GPIO_NUM_13
#define X_DIRECTION_PIN         GPIO_NUM_15
#define Y_STEP_PIN              GPIO_NUM_14
#define Y_DIRECTION_PIN         GPIO_NUM_27
#define Y2_STEP_PIN             GPIO_NUM_26
#define Y2_DIRECTION_PIN        GPIO_NUM_25
#define Z_STEP_PIN              GPIO_NUM_33
#define Z_DIRECTION_PIN         GPIO_NUM_32

#define X_LIMIT_PIN             GPIO_NUM_36
#define Y_LIMIT_PIN             GPIO_NUM_39
#define Z_LIMIT_PIN             GPIO_NUM_34

// OK to comment out to use pin for other features
#define STEPPERS_DISABLE_PIN    GPIO_NUM_21

#define SPINDLE_TYPE            SpindleType::LASER
#define LASER_OUTPUT_PIN        SPINDLE_OUTPUT_PIN
#define SPINDLE_OUTPUT_PIN      GPIO_NUM_17   // labeled SpinPWM

#define SDCARD_DET_PIN          GPIO_NUM_35

#define MACRO_BUTTON_0_PIN      GPIO_NUM_2
#endif

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

#ifdef ILOVELIFE_4AXIS_WITH_PROBE_FLOOD_NEW
#define MACHINE_NAME            "ILoveLife 4axis whit probe and flood"

#define X_STEP_PIN              GPIO_NUM_14
#define X_DIRECTION_PIN         GPIO_NUM_27
#define X2_STEP_PIN             GPIO_NUM_26
#define X2_DIRECTION_PIN        GPIO_NUM_25
#define Y_STEP_PIN              GPIO_NUM_13
#define Y_DIRECTION_PIN         GPIO_NUM_15
#define Z_STEP_PIN              GPIO_NUM_33
#define Z_DIRECTION_PIN         GPIO_NUM_32

// OK to comment out to use pin for other features
#define STEPPERS_DISABLE_PIN    GPIO_NUM_21
#endif

#ifdef ILOVELIFE_BTN
#define MACHINE_NAME            "ILoveLife 4axis whit probe and flood"

#define X_STEP_PIN              GPIO_NUM_13
#define X_DIRECTION_PIN         GPIO_NUM_15
#define Y_STEP_PIN              GPIO_NUM_14
#define Y_DIRECTION_PIN         GPIO_NUM_27
#define Z_STEP_PIN              GPIO_NUM_26
#define Z_DIRECTION_PIN         GPIO_NUM_25
#define A_STEP_PIN              GPIO_NUM_33
#define A_DIRECTION_PIN         GPIO_NUM_32

#define STEPPERS_DISABLE_PIN    GPIO_NUM_21
#define COOLANT_MIST_PIN        GPIO_NUM_22
#define SPINDLE_TYPE            SpindleType::LASER
#define LASER_OUTPUT_PIN        SPINDLE_OUTPUT_PIN
#define SPINDLE_OUTPUT_PIN      GPIO_NUM_17   // labeled SpinPWM
#define COOLANT_FLOOD_PIN       GPIO_NUM_26
#define X_LIMIT_PIN             GPIO_NUM_4
#define Y_LIMIT_PIN             GPIO_NUM_4
#define Z_LIMIT_PIN             GPIO_NUM_4
#define A_LIMIT_PIN             GPIO_NUM_4
#define MACRO_BUTTON_0_PIN      GPIO_NUM_2
#define MACRO_BUTTON_1_PIN      GPIO_NUM_36
#define MACRO_BUTTON_2_PIN      GPIO_NUM_39
#define MACRO_BUTTON_3_PIN      GPIO_NUM_34
#define PROBE_PIN               GPIO_NUM_12  // labeled Probe
#define DEFAULT_HOMING_CYCLE_0  bit(X_AXIS)
#define DEFAULT_HOMING_CYCLE_1  bit(Y_AXIS)
#define DEFAULT_HOMING_CYCLE_2  bit(Z_AXIS)
#define DEFAULT_HOMING_CYCLE_3  bit(A_AXIS)
#endif
// #pragma once

// #define MACHINE_NAME            "BtWriter"
// // #define CUSTOM_CODE_FILENAME    "Custom/CoreXY.cpp"
// #define X_STEP_PIN              GPIO_NUM_27
// #define X_DIRECTION_PIN         GPIO_NUM_26
// #define Y_STEP_PIN              GPIO_NUM_33
// #define Y_DIRECTION_PIN         GPIO_NUM_32
// #define Z_STEP_PIN              GPIO_NUM_14
// #define Z_DIRECTION_PIN         GPIO_NUM_12
// // #define Y2_STEP_PIN              GPIO_NUM_14
// // #define Y2_DIRECTION_PIN         GPIO_NUM_12
// #define X_LIMIT_PIN             GPIO_NUM_35
// #define Y_LIMIT_PIN             GPIO_NUM_34
// // #define Z_LIMIT_PIN             GPIO_NUM_36
// #define STEPPERS_DISABLE_PIN    GPIO_NUM_25
// #define SPINDLE_OUTPUT_PIN      GPIO_NUM_4
// #define SPINDLE_TYPE            SpindleType::LASER
// #define LASER_OUTPUT_PIN        SPINDLE_OUTPUT_PIN
// #define COOLANT_FLOOD_PIN GPIO_NUM_21 // M8
// #define COOLANT_MIST_PIN GPIO_NUM_16 // M7

// #define DEFAULT_HOMING_CYCLE_0  1
// #define DEFAULT_HOMING_CYCLE_1  2
// #define DEFAULT_HOMING_DIR_MASK 7
// #define DEFAULT_HOMING_ENABLE 1
// #define DEFAULT_HARD_LIMIT_ENABLE 0
// #define DEFAULT_SOFT_LIMIT_ENABLE 0

// // #define CUSTOM_CODE_FILENAME    "Custom/G3Macro.cpp"
// // #define MACRO_BUTTON_0_PIN GPIO_NUM_36
// #define MY_CONTROL_SAFETY_DOOR_PIN GPIO_NUM_36
// // #define CONTROL_SAFETY_DOOR_PIN GPIO_NUM_36