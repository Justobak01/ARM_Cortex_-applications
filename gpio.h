/*
 * gpio.h
 *
 *  Created on: 19 sept. 2018
 *      Author: bruno
 */

#ifndef GPIO_H_
#define GPIO_H_


void gpioInitPin2(int, int, int, int);
void gpioInitPin(int, int, int, int, int);
int gpioGetPin(int);
void gpioSetPin(int, int);
unsigned int gpioGetPort(int);
void gpioSetPort(int, int);

#endif /* GPIO_H_ */
