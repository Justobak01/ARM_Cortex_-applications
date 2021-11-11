/*
 * constants.h
 *
 *  Created on: 19 sept. 2018
 *      Author: bruno
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

/* RCC section */

#define MCO1 0	// pin PA8
#define MCO2 1	// pin PC9
#define CKOUT_DISABLE -1
#define CKOUT_SYSCLK 0
#define CKOUT_PLLI2S 1
#define CKOUT_HSE 2
#define CKOUT_PLL 3
#define CKOUT_HSI 0
#define CKOUT_LSE 1
#define MCO_DIV_1 0
#define MCO_DIV_2 4
#define MCO_DIV_3 5
#define MCO_DIV_4 6
#define MCO_DIV_5 7



#define QUERY_SYSCLK 0
#define QUERY_AHBCLK 1
#define QUERY_APB1CLK 2
#define QUERY_APB2CLK 3


#define AHB_PRESCALER 0
#define APB1_PRESCALER  1
#define APB2_PRESCALER  2

#define APBX_DIV_1 0
#define APBX_DIV_2 4
#define APBX_DIV_4 5
#define APBX_DIV_8 6
#define APBX_DIV_16 7

#define AHB_DIV_1 0
#define AHB_DIV_2 8
#define AHB_DIV_4 9
#define AHB_DIV_8 10
#define AHB_DIV_16 11
#define AHB_DIV_64 12
#define AHB_DIV_128 13
#define AHB_DIV_256 14
#define AHB_DIV_512 15

#define HSE_BYPASS 0x00040000
#define HSE_ON 0x00010000

#define SYSCLK_DEFAULT 0xFFFFFFFC
#define SYSCLK_HSI 0
#define SYSCLK_HSE 1
#define SYSCLK_PLLP 2
#define SYSCLK_PLLR 3

#define PLL_CLK_HSI 0
#define PLL_CLK_HSE 1

/* GPIO section */

#define LD1 16
#define LD2 23
#define LD3 30

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5
#define PORTG 6
#define PORTH 7

#define	PA0		0
#define	PA1		1
#define	PA2		2
#define	PA3		3
#define	PA4		4
#define	PA5		5
#define	PA6		6
#define	PA7		7
#define	PA8		8
#define	PA9		9
#define	PA10	10
#define	PA11	11
#define	PA12	12
#define	PA13	13
#define	PA14	14
#define	PA15	15
#define	PB0		16
#define	PB1		17
#define	PB2		18
#define	PB3		19
#define	PB4		20
#define	PB5		21
#define	PB6		22
#define	PB7		23
#define	PB8		24
#define	PB9		25
#define	PB10	26
#define	PB11	27
#define	PB12	28
#define	PB13	29
#define	PB14	30
#define	PB15	31
#define	PC0		32
#define	PC1		33
#define	PC2		34
#define	PC3		35
#define	PC4		36
#define	PC5		37
#define	PC6		38
#define	PC7		39
#define	PC8		40
#define	PC9		41
#define	PC10	42
#define	PC11	43
#define	PC12	44
#define	PC13	45
#define	PC14	46
#define	PC15	47
#define	PD0		48
#define	PD1		49
#define	PD2		50
#define	PD3		51
#define	PD4		52
#define	PD5		53
#define	PD6		54
#define	PD7		55
#define	PD8		56
#define	PD9		57
#define	PD10	58
#define	PD11	59
#define	PD12	60
#define	PD13	61
#define	PD14	62
#define	PD15	63
#define	PE0		64
#define	PE1		65
#define	PE2		66
#define	PE3		67
#define	PE4		68
#define	PE5		69
#define	PE6		70
#define	PE7		71
#define	PE8		72
#define	PE9		73
#define	PE10	74
#define	PE11	75
#define	PE12	76
#define	PE13	77
#define	PE14	78
#define	PE15	79
#define	PF0		80
#define	PF1		81
#define	PF2		82
#define	PF3		83
#define	PF4		84
#define	PF5		85
#define	PF6		86
#define	PF7		87
#define	PF8		88
#define	PF9		89
#define	PF10	90
#define	PF11	91
#define	PF12	92
#define	PF13	93
#define	PF14	94
#define	PF15	95
#define	PG0		96
#define	PG1		97
#define	PG2		98
#define	PG3		99
#define	PG4		100
#define	PG5		101
#define	PG6		102
#define	PG7		103
#define	PG8		104
#define	PG9		105
#define	PG10	106
#define	PG11	107
#define	PG12	108
#define	PG13	109
#define	PG14	110
#define	PG15	111
#define	PH0		112
#define	PH1		113
#define	PH2		114
#define	PH3		115
#define	PH4		116
#define	PH5		117
#define	PH6		118
#define	PH7		119
#define	PH8		120
#define	PH9		121
#define	PH10	122
#define	PH11	123
#define	PH12	124
#define	PH13	125
#define	PH14	126
#define	PH15	127

#define INPUT 0x00
#define OUTPUT 0x10
#define AF0 0x20
#define AF1 0x21
#define AF2 0x22
#define AF3 0x23
#define AF4 0x24
#define AF5 0x25
#define AF6 0x26
#define AF7 0x27
#define AF8 0x28
#define AF9 0x29
#define AF10 0x2A
#define AF11 0x2B
#define AF12 0x2C
#define AF13 0x2D
#define AF14 0x2E
#define AF15 0x2F
#define ANALOG 0x30

#define LOW_SPEED 0
#define MEDIUM_SPEED 1
#define HIGH_SPEED 2
#define VERY_HIGH_SPEED 3

#define NOPULL 0
#define PULLUP 1
#define PULLDOWN 2

#define PUSH_PULL 0
#define OPEN_DRAIN 1

#define INPUT_FLOAT 0
#define INPUT_PULL_UP 1
#define INPUT_PULL_DOWN 2
#define OUTPUT_PUSH_PULL 0
#define OUTPUT_OPEN_DRAIN 1

#define NONE 0

/* SPI section */

#define SPI_MODE_0 0
#define SPI_MODE_1 1
#define SPI_MODE_2 2
#define SPI_MODE_3 3

#define SPI_CLK_DIV_2 0
#define SPI_CLK_DIV_4 1
#define SPI_CLK_DIV_8 2
#define SPI_CLK_DIV_16 3
#define SPI_CLK_DIV_32 4
#define SPI_CLK_DIV_64 5
#define SPI_CLK_DIV_128 6
#define SPI_CLK_DIV_256 7

#define SPI_MSBFIRST 0
#define SPI_LSBFIRST 1

#define SPI_DATA_FORMAT_8 0
#define SPI_DATA_FORMAT_16 1

/* I2C section */

#define I2C_WR 0
#define I2C_RD 1
#define I2C_ACK 1
#define I2C_NACK 0

/* lcd section */
#define DEC 0
#define HEX 1


#endif /* CONSTANTS_H_ */
