/*
 * i2c.h
 *
 *  Created on: 10 oct. 2018
 *      Author: bruno
 */

#ifndef I2C_H_
#define I2C_H_

void i2c1Init(void);
void i2c1Init(int);
void i2c1Init(int, int);
void i2c1Init(int, int, int);

//void i2c1BeginTransmission(uint8_t, int);
uint8_t i2c1BeginTransmission(uint8_t, int);
void i2c1WriteByte(uint8_t);
uint8_t i2c1ReadByte(int);
void i2c1EndTransmission(void);

int i2c1ScanBus(uint8_t *);
int i2c1ScanBus(uint8_t *, int, int);

#endif /* I2C_H_ */
