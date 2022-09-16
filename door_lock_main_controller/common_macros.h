 /******************************************************************************
 *
 * Module: common_macros
 *
 * File Name: common_macros.h
 *
 * Description: Commonly used macros in my code
 *
 * Author: Ziad Ahmed
 *
 *******************************************************************************/


#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

/*SET a specific bit in a register*/

#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/*CLEAR a specific bit in a register*/

#define CLEAR_BIT(REG,BIT) (REG&=~(1<<BIT))

/*TOGGLE a specific bit in a register*/

#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/*ROTATE RIGHT a register for a number of times*/

#define ROR(REG,NUM) ( REG= (REG >> NUM) | (REG<<(8-NUM)) )

/*ROTATE LEFT a register for a number of times*/

#define ROL(REG,NUM) ( REG= (REG << NUM) | (REG>>(8-NUM)) )

/*CHECK if a bit is SET*/

#define BIT_IS_SET(REG,BIT) ( REG & (1 << BIT) )

/*CHECK if a bit is CLEAR*/

#define BIT_IS_CLEAR(REG,BIT) ( ! (REG & (1<<BIT)) )

/*READ the value of certain bit */

#define READ_BIT(REG,BIT) ( REG & (1 << BIT) )

/*Gives the higher nibble of data */

#define HIGH_NIBBLE_OF(data) (data>>4)

/*Gives the LOWER nibble of data */



#endif /* COMMON_MACROS_H_ */
