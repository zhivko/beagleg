// -*- mode: c; c-basic-offset: 2; indent-tabs-mode: nil; -*-
// (c) 2013, 2014 Henner Zeller <h.zeller@acm.org>
//
// This file is part of BeagleG. http://github.com/hzeller/beagleg
//
// BeagleG is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// BeagleG is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with BeagleG.  If not, see <http://www.gnu.org/licenses/>.
//

// To be read by *.c and *.p file, so only // comments and simple defines.

#ifndef __MOTOR_INTERFACE_CONSTANTS_H
#define __MOTOR_INTERFACE_CONSTANTS_H

// Frequency we use for our timer. The CPU uses two CPU cycles per busy loop,
// so we divide CPU freq by that.
// A hardware timer might run natively at full speed.
#define TIMER_FREQUENCY (200000000 / 2)

#define STATE_EMPTY  0   // Queue element empty, ready to be filled by host
#define STATE_FILLED 1   // Queue element filled by host, to be picked up by PRU
#define STATE_EXIT   2   // Filled by host, no parameters; tells PRU to exit.

#define QUEUE_LEN 16

// In calculation of delay cycles: number of bits shifted
// for higher resolution.
#define DELAY_CYCLE_SHIFT 5

// Memory space mapped to the GPIO registers
#define GPIO_0_BASE       0x44e07000
#define GPIO_1_BASE       0x4804c000
#define GPIO_2_BASE       0x481ac000
#define GPIO_3_BASE       0x481ae000

// GPIO Registers
#define GPIO_OE           0x134
#define GPIO_DATAIN       0x138
#define GPIO_DATAOUT      0x13c
#define GPIO_CLEARDATAOUT 0x190
#define GPIO_SETDATAOUT   0x194

//
// Generic GPIO mapping pin definitions for the BeagleBone cape
// Here, we put them together in one convenient value which is used for
// the generic pin-mapping in BeagleG
//

#define PIN_P9_11  (GPIO_0_BASE | 30)  // UART4_RXD
#define PIN_P9_12  (GPIO_1_BASE | 28)
#define PIN_P9_13  (GPIO_0_BASE | 31)  // UART4_TXD
#define PIN_P9_14  (GPIO_1_BASE | 18)  // EHRPWM1A
#define PIN_P9_15  (GPIO_1_BASE | 16)
#define PIN_P9_16  (GPIO_1_BASE | 19)  // EHRPWM1B
#define PIN_P9_17  (GPIO_0_BASE |  5)  // I2C1_SCL
#define PIN_P9_18  (GPIO_0_BASE |  4)  // I2C1_SDA
#define PIN_P9_19  (GPIO_0_BASE | 13)  // I2C2_SCL
#define PIN_P9_20  (GPIO_0_BASE | 12)  // I2C2_SDA
#define PIN_P9_21  (GPIO_0_BASE |  3)  // UART2_TXD
#define PIN_P9_22  (GPIO_0_BASE |  2)  // UART2_RXD
#define PIN_P9_23  (GPIO_1_BASE | 17)
#define PIN_P9_24  (GPIO_0_BASE | 15)  // UART1_TXD
#define PIN_P9_25  (GPIO_3_BASE | 21)
#define PIN_P9_26  (GPIO_0_BASE | 14)  // UART1_RXD
#define PIN_P9_27  (GPIO_3_BASE | 19)
#define PIN_P9_28  (GPIO_3_BASE | 17)  // SPI1_CS0
#define PIN_P9_29  (GPIO_3_BASE | 15)  // SPI1_D0 (MISO)
#define PIN_P9_30  (GPIO_3_BASE | 16)  // SPI1_D1 (MOSI)
#define PIN_P9_31  (GPIO_3_BASE | 14)  // SPI1_SCK
#define PIN_P9_41  (GPIO_0_BASE | 20)  // CLKOUT2
#define PIN_P9_42  (GPIO_0_BASE |  7)

#define PIN_P8_7   (GPIO_2_BASE |  2)  // TIMER4
#define PIN_P8_8   (GPIO_2_BASE |  3)  // TIMER7
#define PIN_P8_9   (GPIO_2_BASE |  5)  // TIMER5
#define PIN_P8_10  (GPIO_2_BASE |  4)  // TIMER6
#define PIN_P8_11  (GPIO_1_BASE | 13)
#define PIN_P8_12  (GPIO_1_BASE | 12)
#define PIN_P8_13  (GPIO_0_BASE | 23)  // EHRPWM2B
#define PIN_P8_14  (GPIO_0_BASE | 26)
#define PIN_P8_15  (GPIO_1_BASE | 15)
#define PIN_P8_16  (GPIO_1_BASE | 14)
#define PIN_P8_17  (GPIO_0_BASE | 27)
#define PIN_P8_18  (GPIO_2_BASE |  1)
#define PIN_P8_19  (GPIO_0_BASE | 22)  // EHRPWM2A
#define PIN_P8_26  (GPIO_1_BASE | 29)

#define GPIO_NOT_MAPPED  0


// The following file is included from the hardware directory
// of the cape we are compiling for.
// If this include fails, check the HARDWARE_TARGET in the
// Makefile: it must match a subdirectory in hardware/
// (because of a broken implementation of the include directive in
// the pasm, this needs to be in angle brackets).
#include <beagleg-pin-mapping.h>

// Make sure all GPIOs are defined to avoid compiler errors

// OUTPUTs - There are up to 9 motors, each requires a step signal
// Ony the PRU code toggles these GPIOs
#ifndef MOTOR_1_STEP_GPIO
#define MOTOR_1_STEP_GPIO  GPIO_NOT_MAPPED
#endif
#ifndef MOTOR_2_STEP_GPIO
#define MOTOR_2_STEP_GPIO  GPIO_NOT_MAPPED
#endif
#ifndef MOTOR_3_STEP_GPIO
#define MOTOR_3_STEP_GPIO  GPIO_NOT_MAPPED
#endif
#ifndef MOTOR_4_STEP_GPIO
#define MOTOR_4_STEP_GPIO  GPIO_NOT_MAPPED
#endif
#ifndef MOTOR_5_STEP_GPIO
#define MOTOR_5_STEP_GPIO  GPIO_NOT_MAPPED
#endif
#ifndef MOTOR_6_STEP_GPIO
#define MOTOR_6_STEP_GPIO  GPIO_NOT_MAPPED
#endif
#ifndef MOTOR_7_STEP_GPIO
#define MOTOR_7_STEP_GPIO  GPIO_NOT_MAPPED
#endif
#ifndef MOTOR_8_STEP_GPIO
#define MOTOR_8_STEP_GPIO  GPIO_NOT_MAPPED
#endif
#ifndef MOTOR_9_STEP_GPIO
#define MOTOR_9_STEP_GPIO  GPIO_NOT_MAPPED
#endif

// OUTPUTs - There are up to 9 motors, each requires a direction signal
// Ony the PRU code toggles these GPIOs
#ifndef MOTOR_1_DIR_GPIO
#define MOTOR_1_DIR_GPIO   GPIO_NOT_MAPPED
#endif
#ifndef MOTOR_2_DIR_GPIO
#define MOTOR_2_DIR_GPIO   GPIO_NOT_MAPPED
#endif
#ifndef MOTOR_3_DIR_GPIO
#define MOTOR_3_DIR_GPIO   GPIO_NOT_MAPPED
#endif
#ifndef MOTOR_4_DIR_GPIO
#define MOTOR_4_DIR_GPIO   GPIO_NOT_MAPPED
#endif
#ifndef MOTOR_5_DIR_GPIO
#define MOTOR_5_DIR_GPIO   GPIO_NOT_MAPPED
#endif
#ifndef MOTOR_6_DIR_GPIO
#define MOTOR_6_DIR_GPIO   GPIO_NOT_MAPPED
#endif
#ifndef MOTOR_7_DIR_GPIO
#define MOTOR_7_DIR_GPIO   GPIO_NOT_MAPPED
#endif
#ifndef MOTOR_8_DIR_GPIO
#define MOTOR_8_DIR_GPIO   GPIO_NOT_MAPPED
#endif
#ifndef MOTOR_9_DIR_GPIO
#define MOTOR_9_DIR_GPIO   GPIO_NOT_MAPPED
#endif

// OUtPUT - Enables the drivers, can be active-low (default) or high
#ifndef MOTOR_ENABLE_GPIO
#define MOTOR_ENABLE_GPIO  GPIO_NOT_MAPPED
#endif
#ifndef MOTOR_ENABLE_IS_ACTIVE_HIGH
#define MOTOR_ENABLE_IS_ACTIVE_HIGH 0
#endif

// OUTPUT - Turns the ATX power on/off (M80: on; M81: off)
#ifndef MACHINE_PWR_GPIO
#define MACHINE_PWR_GPIO   GPIO_NOT_MAPPED
#endif

// INPUT - Allows detecting a hardware E-Stop
#ifndef ESTOP_HW_GPIO
#define ESTOP_HW_GPIO      GPIO_NOT_MAPPED
#endif

// OUTPUT - Generates a software E-Stop (M0; cleared with M999)
#ifndef ESTOP_SW_GPIO
#define ESTOP_SW_GPIO      GPIO_NOT_MAPPED
#endif

// OUTPUT - General purpose LED (toggles with M24 until start button is pressed)
#ifndef LED_GPIO
#define LED_GPIO           GPIO_NOT_MAPPED
#endif

// INPUT - Starts motion generation after input is low (M24)
#ifndef START_GPIO
#define START_GPIO         GPIO_NOT_MAPPED
#endif

// INPUT - Pauses motion generation when input is low
#ifndef PAUSE_GPIO
#define PAUSE_GPIO         GPIO_NOT_MAPPED
#endif


// OUTPUTs - Auxillary outputs; updated by PRU with each queue segment
// Aux 1 = Mist control on/off (M7: on; M9: off)
// Aux 2 = Flood control on/off (M8: on; M9: off)
// Aux 3 = Vacuum control on/off (M10: on; M11: off)
// Aux 4 = Spindle control on/off (M3/M4: on; M5: off)
// Aux 5 = Spindle direction (M3: clockwise; M4: counterclockwise)
#ifndef AUX_1_GPIO
#define AUX_1_GPIO         GPIO_NOT_MAPPED
#endif
#ifndef AUX_2_GPIO
#define AUX_2_GPIO         GPIO_NOT_MAPPED
#endif
#ifndef AUX_3_GPIO
#define AUX_3_GPIO         GPIO_NOT_MAPPED
#endif
#ifndef AUX_4_GPIO
#define AUX_4_GPIO         GPIO_NOT_MAPPED
#endif
#ifndef AUX_5_GPIO
#define AUX_5_GPIO         GPIO_NOT_MAPPED
#endif

// OUTPUTs - PWM outputs
#ifndef PWM_1_GPIO
#define PWM_1_GPIO         GPIO_NOT_MAPPED
#endif
#ifndef PWM_2_GPIO
#define PWM_2_GPIO         GPIO_NOT_MAPPED
#endif
#ifndef PWM_3_GPIO
#define PWM_3_GPIO         GPIO_NOT_MAPPED
#endif
#ifndef PWM_4_GPIO
#define PWM_4_GPIO         GPIO_NOT_MAPPED
#endif

// INPUTs - Endstops
#ifndef END_1_GPIO
#define END_1_GPIO         GPIO_NOT_MAPPED
#endif
#ifndef END_2_GPIO
#define END_2_GPIO         GPIO_NOT_MAPPED
#endif
#ifndef END_3_GPIO
#define END_3_GPIO         GPIO_NOT_MAPPED
#endif
#ifndef END_4_GPIO
#define END_4_GPIO         GPIO_NOT_MAPPED
#endif
#ifndef END_5_GPIO
#define END_5_GPIO         GPIO_NOT_MAPPED
#endif
#ifndef END_6_GPIO
#define END_6_GPIO         GPIO_NOT_MAPPED
#endif

// Friendly names for the GPIO signals
#ifndef FAN_GPIO
#define FAN_GPIO           GPIO_NOT_MAPPED
#endif

#endif // __MOTOR_INTERFACE_CONSTANTS_H
