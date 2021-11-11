/* Includes */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "stm32f446zeLib.h"
#include "stm32f4xx.h"

/* Private macro */

/* Private variables */
/* Private function prototypes */
/* Private functions */

liquidCrystal lcd(PG12, PG9, PE1, PG0, PF0, PF1); // Shield V2.0

/*
**===========================================================================
**
** run mode, reference
**
**===========================================================================
*/



void led1_Config(){
  RCC->CR &= ~RCC_CR_HSION; // Disabling HSI
  RCC->CR |= RCC_CR_HSION; // Re-anabling HSI 
  rccCkout(MCO1, CKOUT_HSI, MCO_DIV_1, MEDIUM_SPEED); // Verifying HSI clock works
// Congifguring GPIOG Port
  RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOGEN;
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN; // Enabling Peripheral G clock 
  GPIOG->MODER |= GPIO_MODER_MODE11_0; // Setting Port G as output
  GPIOG->OTYPER &= ~GPIO_OTYPER_OT11; //   Selecting Push-Pull for the output
  GPIOG->OSPEEDR|= GPIO_OSPEEDER_OSPEEDR11_0; // Selecting medium Speed 
  GPIOG->PUPDR |= GPIO_PUPDR_PUPD11_0;  // Setting pull up
//GPIOG->ODR |= GPIO_ODR_OD11; // Writing 1 to G11 output
  }
void Blink_with_PG11() {
  // Trying to swith with Pull-up
 //GPIOG->PUPDR |= GPIO_PUPDR_PUPD11_0;
  //delay(1000); 
  //GPIOG->PUPDR &= ~GPIO_PUPDR_PUPD11_0;
  // delay(1000)

  // Blinking with BSRR
  /*GPIOG->BSRR|= GPIO_BSRR_BS11;
  delay(1000);
  GPIOG->BSRR |= GPIO_BSRR_BR11;
  delay(1000);*/

  //Trying with ODR
  GPIOG->ODR |= GPIO_ODR_OD11;


  delay(500);
  GPIOG->ODR &= ~GPIO_ODR_OD11;
  delay(500);
}

// Coding the interrupt
void EXTI0_IRQHandler(void){
  for(int i=0; i<10; i++){
  Blink_with_PG11();
  delay(500); 
  }
  //Testing if the interreupts works if it occurs during an interrupt 
  //EXTI->SWIER|= EXTI_SWIER_SWIER0;
  // The interrupt is not served twice
  NVIC_ClearPendingIRQ(EXTI0_IRQn);
  EXTI->PR |= EXTI_PR_PR0;
  }


int main(void) {
__disable_irq();
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print((char *)"run mode");

  int j = 0;
  // prescalers at min value

  rccSetPrescaler(AHB_PRESCALER, AHB_DIV_1);
  rccSetPrescaler(APB1_PRESCALER, APBX_DIV_1);
  rccSetPrescaler(APB2_PRESCALER, APBX_DIV_1);
  
  // Configuring port D for button use 
  RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIODEN;
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; // Enabling Peripheral D clock 
  GPIOD->MODER &= ~ GPIO_MODER_MODE0_0; // Setting Port D as input


  // Configuring interrupts 
  RCC->AHB1ENR |= 0x000000FF; // activates clock for ports A to H
  RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
  GPIOB->MODER &= ~ GPIO_MODER_MODE11_0; // Setting Port B as input
  SYSCFG->EXTICR[0] |= 0x1; // Enabling external interrupts on PB0;
  GPIOB->PUPDR |= GPIO_PUPDR_PUPD0_0;  // Setting pull up
  EXTI->FTSR |= EXTI_FTSR_TR0; 
  EXTI->RTSR &= ~EXTI_RTSR_TR0; // Enabling interrupts at rising edges
  EXTI->IMR |= EXTI_IMR_IM0; 

  NVIC_EnableIRQ(EXTI0_IRQn); // enabling Interrupts for
  NVIC_SetPriority(EXTI0_IRQn, 5);
   led1_Config(); // configuring the led
  __enable_irq();// enabling all Interrupts 

   //EXTI->SWIER|= EXTI_SWIER_SWIER0; 
 
 
 // if (GPIO_IDR_ID0 & 0x1){ // if there is a signal form the button
 // NVIC_SetPendingIRQ(EXTI0_IRQn); // The IRQ is set
 //}
  

  while (1) {
    j++;
  }
}
/*

/*
**===========================================================================
**
** sleep mode, event
**
**===========================================================================
*/

/*
int main(void) {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print((char *)"sleep mode");

  // set up the wake-up source
  
// activates clock for ports A to H and gonfigure GPIOs
 

  // clock gating in  low_power mode (NOT AHB1 for port A!!!)



  // unused pins in analog mode-> no schmitt trigger

  //GPIOA->MODER |= 0xC3F0FFFC; // excepted 0, 8,9, 13,14
  //GPIOB->MODER |= 0xFFFFFF3F;	// excepted 3
  //GPIOC->MODER |= 0x0FFFFFFF;	// excepted 14,15
  //GPIOD->MODER |= 0xFFF0FFFF;	// excepted 8,9
  //GPIOE->MODER |= 0xFFFFFFFF;
  //GPIOF->MODER |= 0xFFFFFFFF;
  //GPIOG->MODER |= 0xFF3FC555;	// excepted 6, 11
  //GPIOH->MODER |= 0x55555555;

  // pull-up on unused inputs, default values not modified

  GPIOA->PUPDR |= 0x01505555; // excepted 8,9, 13,14
  GPIOB->PUPDR |= 0x55555415; // excepted 3
  GPIOC->PUPDR |= 0x05555555; // excepted 14,15
  GPIOD->PUPDR |= 0x55505555; // excepted 8,9
  GPIOE->PUPDR |= 0x55555555;
  GPIOF->PUPDR |= 0x55555555;
  GPIOG->PUPDR |= 0x55154555; // excepted 6, 11
  GPIOH->PUPDR |= 0x55555555;

   // full-speed in normal mode
   

  while (1) {
  
   
    for (int i = 0; i < 5; i++) 
    {
      gpioSetPin(PG11, 1); // PG11 à 1
      delay(100);
      gpioSetPin(PG11, 0); // PG11 à 0
      delay(100);
    }

   // prescalers at max value

   

    // low-power mode
    

     // back at full-speed in normal mode
   

  }
}

*/

/*
**===========================================================================
**
** stop mode
**
**===========================================================================
*/

/*
#define REGLP
#define FLASHDOWN
#define UNDERDRIVE

int main(void) {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print((char *)"stop mode");

  // set up the wake-up source

  // clock gating in  low_power mode  (NOT AHB1 for port A!!!)

  // activates clock for ports A to H and gonfigure GPIOs

  // unused pins in analog mode-> no schmitt trigger

  GPIOA->MODER |= 0xC3F0FFFC; // excepted 0, 8,9, 13,14
  GPIOB->MODER |= 0xFFFFFF3F; // excepted 3
  GPIOC->MODER |= 0x0FFFFFFF; // excepted 14,15
  GPIOD->MODER |= 0xFFF0FFFF; // excepted 8,9
  GPIOE->MODER |= 0xFFFFFFFF;
  GPIOF->MODER |= 0xFFFFFFFF;
  GPIOG->MODER |= 0xFF3FC555; // excepted 6, 11
  GPIOH->MODER |= 0x55555555;

  while (1) {

    // full-speed in normal mode



    for (int i = 0; i < 5; i++) // 5 blinks of PG11
    {
      gpioSetPin(PG11, 1); // PG11 à 1
      delay(100);
      gpioSetPin(PG11, 0); // PG11 à 0
      delay(100);
    }

    // back to low-speed mode


    // SLEEPDEEP=1 low-power mode = stop or standby mode


    // clear the WUF flag


    // Enter stop mode when the CPU enters deepsleep


    // different options for stop mode

#ifndef REGLP
    PWR->CR &= ~PWR_CR_LPDS; // normal voltage regulator
#else
    PWR->CR |= PWR_CR_LPDS; // low-power voltage regulator
#endif

#ifndef FLASHDOWN
    PWR->CR &= ~PWR_CR_FPDS; // flash not power-down in stop mode
#else
    PWR->CR |= PWR_CR_FPDS; // flash power-down in stop mode
#endif

#ifndef UNDERDRIVE
    PWR->CR &= ~PWR_CR_UDEN; // under-drive disable
#else
    PWR->CR |= PWR_CR_UDEN; // under-drive enable
#endif


    asm("wfe");
  }
}

* /
    /*
**===========================================================================
**
** standby mode
**
**===========================================================================
*/

//int main(void) {
//  lcd.begin(16, 2);
//  lcd.clear();
//  lcd.print((char *)"standby mode");

//  // full-speed in normal mode

//  // init PG11

//  while (1) {

//    for (int i = 0; i < 5; i++) // 5blinks on PG11
//    {
//      gpioSetPin(PG11, 1); // PG11 à 1
//      delay(100);
//      gpioSetPin(PG11, 0); // PG11 à 0
//      delay(100);
//    }

//    // SLEEPDEEP=1 low-power mode = stop or standby mode
    

//    // clear the WUF flag
    

//    // Enter Standby mode when the CPU enters deepsleep
    

//    asm("wfe");
//  }
//}