/*
 * liquidCrystal.h
 *
 *  Created on: 30 janv. 2019
 *      Author: bruno
 */

#ifndef LIQUIDCRYSTAL_H_
#define LIQUIDCRYSTAL_H_

class liquidCrystal {

protected:
	int _RS;
	int _E;
	int _D4;
	int _D5;
	int _D6;
	int _D7;
	int _rows;
	int _colums;


public:
	liquidCrystal(int, int, int, int, int, int);
	void begin(int, int);
	void clear(void);
	void setCursor(int, int);
	void print(char *);
	void print(float, int);
	void print(int, int);


	void nibbleWrite(char, int);
	void lcdCommand(unsigned char);
	void lcdData(char);
};

#endif /* LIQUIDCRYSTAL_H_ */
