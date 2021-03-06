/* -*- mode: c; c-basic-offset: 2; indent-tabs-mode: nil; -*-
 * (c) 2013, 2014 Henner Zeller <h.zeller@acm.org>
 *
 * This file is part of BeagleG. http://github.com/hzeller/beagleg
 *
 * BeagleG is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BeagleG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BeagleG.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _BEAGLEG_GCODE_MACHINE_CONTROL_H_
#define _BEAGLEG_GCODE_MACHINE_CONTROL_H_

#include "gcode-parser.h"

struct MotorOperations;

/* Configuration constants for the controller.
 * Parameters in the arrays are always indexed by logical axes, e.g. AXIS_X.
 * The output mapping to the physical driver is controlled by output_mapping
 */
struct MachineControlConfig {
  // Arrays with values for each axis
  float steps_per_mm[GCODE_NUM_AXES];   // Steps per mm for each logical axis.
  float move_range_mm[GCODE_NUM_AXES];  // Range of axes in mm (0..range[axis]). -1: no limit

  float max_feedrate[GCODE_NUM_AXES];   // Max feedrate for axis (mm/s)
  float acceleration[GCODE_NUM_AXES];   // Max acceleration for axis (mm/s^2)

  float speed_factor;         // Multiply feed with. Should be 1.0 by default.

  // The follwing parameter determines which logical axis ends up
  // on which physical plug location.
  //
  // The 'axis_mapping' determines how to map a logical axis (e.g. 'X') to
  // a connector position. The string position represents the
  // position on the board (sequence of connectors), while the character at
  // that position describes the logical axis. Typicaly, this is just
  // "XZYEABC"; for reasons such as using a double-connector, one might
  // have a different mapping, e.g. "XZE_Y". Underscores represent axis that
  // are not mapped.
  const char *axis_mapping;     // Mapping of axis-name (character in string)
                                // to physical location (position in string).
                                // Assumed "XYZEABC" if NULL.
                                // Axis name '_' for skipped placeholder.
                                // Not mentioned axes are not handled.

  // Position in these strings is the connector position of input switches.
  // Lower case: just regular stopswitch, Upper case: used for homing.
  const char *min_endswitch;       // Letter: affected axis.
  const char *max_endswitch;       // Letter: affected axis.
  const char *endswitch_polarity;  // Letter: trigger logic level.

  const char *home_order;        // Order in which axes are homed.

  char require_homing;          // Require homing before any moves.
  char range_check;             // Do machine limit checks. Default 1.
  char debug_print;             // Print step-tuples to output_fd if 1.
  char synchronous;             // Don't queue, wait for command to finish if 1.
};


typedef struct GCodeMachineControl GCodeMachineControl_t;  // Opaque type.

// Initializes configuration with default values.
void gcode_machine_control_default_config(struct MachineControlConfig *cfg);

// Initialize the motor control with the given configuration and backend
// motor control operations.
// This internally creates a copy of the configuration so no need for
// the value to stay around after this call (also, the configuration might
// change internally depending on GCode commands.)
//
// The MotorOperations struct provide the low-level motor control ops.
// msg_stream, if non-NULL, sends back return messages on the GCode channel.
// Returns 0 on success.
GCodeMachineControl_t *gcode_machine_control_new(
                       const struct MachineControlConfig *config,
                       struct MotorOperations *motor_ops,
                       FILE *msg_stream);

// Sets where the messages go.
void gcode_machine_control_set_msg_out(GCodeMachineControl_t *object,
                                       FILE *msg_stream);

// ---
// TODO(hzeller) the following are only needed to configure the gcode parser. Maybe
// this is something the gcode_machine_control should actually do by itself.
// ---

// Get the struct to receive events.
void gcode_machine_control_init_callbacks(GCodeMachineControl_t *object,
                                          struct GCodeParserCb *callbacks);

// Get home position of this machine. This depends on the axis switches.
void gcode_machine_control_get_homepos(GCodeMachineControl_t *obj, float *pos);

void gcode_machine_control_delete(GCodeMachineControl_t *object);

#endif //  _BEAGLEG_GCODE_MACHINE_CONTROL_H_
