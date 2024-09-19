#include <stdio.h>
#include <stdint.h>
#include "../inc/ST7735.h"
#include "../inc/PLL.h"
#include "../inc/tm4c123gh6pm.h"
#include "../inc/Timer0A.h"
#include "Lab3.h"

void Switch_Init(){
	// PC4, PC5, PC6, PC7, PF4 INPUT
	SYSCTL_RCGCGPIO_R |= 0x24;
	while((SYSCTL_PRGPIO_R & 0x24) != 0x24){}
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R = 0x10;
	GPIO_PORTF_DEN_R = 0x10;
	GPIO_PORTF_DIR_R = 0x10;
	
	GPIO_PORTC_LOCK_R = 0x4C4F434B;
	GPIO_PORTC_CR_R = 0xF0;
	GPIO_PORTC_DEN_R |= 0xF0;
	GPIO_PORTC_DIR_R &= 0x0F;
	
	SYSCTL_RCGCGPIO_R |= 0x20;
	while((SYSCTL_PRGPIO_R & 0x20) == 0);
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R = 0xFF;
	GPIO_PORTF_DEN_R = 0x0E;
	GPIO_PORTF_DIR_R = 0x0E;
}

void LED_init(){
	GPIO_PORTE_DEN_R = 0x01;
	GPIO_PORTE_DIR_R = 0x01;
}

uint32_t Switch_In(void){
  return (GPIO_PORTC_DATA_R);
}

void LED_Out(uint32_t data){
		GPIO_PORTF_DATA_R = data;
}

