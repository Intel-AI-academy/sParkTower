/*
 * control_motor.h
 *
 *  Created on: Jan 12, 2024
 *      Author: iot16
 */

#ifndef INC_CONTROL_MOTOR_H_
#define INC_CONTROL_MOTOR_H_

#ifdef __cplusplus
extern "C" {
#endif

void control_motor(int);
void move_to_parking_slot(int, int);
void get_out_parking_tower(int);

#ifdef __cplusplus
}
#endif

#endif /* INC_CONTROL_MOTOR_H_ */
