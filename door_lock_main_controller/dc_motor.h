 /******************************************************************************
 *
 * Module: dc_motor
 *
 * File Name: dc_motor.h
 *
 * Description: 
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_



/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define MOTOR_PORT 'C'
#define MOTOR_IN1 6
#define MOTOR_IN2 7


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void MOTOR_init(void);
void MOTOR_start_clockwise(void);
void MOTOR_start_anticlock(void);
void MOTOR_stop(void);
#endif /* DC_MOTOR_H_ */
