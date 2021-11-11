/*
 * rcc.h
 *
 *  Created on: 19 sept. 2018
 *      Author: bruno
 */

#ifndef RCC_H_
#define RCC_H_

void rccCkout(int, int, int, int);
float rccQueryClk(int, int, int);
void rccSetPrescaler(int, int);
int rccSetPll(int, int, int, int, int, int);
void rccSetSysclkSource(int);

#endif /* RCC_H_ */
