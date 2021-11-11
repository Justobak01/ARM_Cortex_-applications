/*
 * usart.h
 *
 *  Created on: 25 sept. 2018
 *      Author: bruno
 */

#ifndef USART_H_
#define USART_H_

/* USART 1 */
/*
#define USART1_RX_BUFFER_SIZE 4
		char usart1RxBuffer[USART1_RX_BUFFER_SIZE];
		int usart1RxBufferReadPointer;
		volatile int usart1RxBufferWritePointer;
		volatile int usart1RxBufferAvailableBytes;
*/

/*
void usart1Init(int, int);
void usart1WriteByte(int);
void usart1WriteString(char*);
char usart1ReadChar(void);
int usart1IsAvailable(void);
void usart1WriteInRxBuffer(void);
char usart1ReadFromRxBuffer(void);
*/

/* USART 3 */
void usart3Init(int, int);

void usart3WriteByte(int);
void usart3WriteByte(uint8_t);
void usart3WriteByte(char);

void usart3WriteString(char*);

int usart3IsCharAvailable(void);
char usart3ReadChar(void);

#endif /* USART_H_ */
