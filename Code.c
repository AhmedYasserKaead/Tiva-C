#include <stdint.h>
#include <stdio.h>
#include "C:\Users\ayaser\CLionProjects\dada\TMC123GH6PM.h"
#define INPUT 0
#define OUTPUT 1

void Initi(uint8_t dir)
{
    SYSCTL_REGCGC2_REG |= 0x20;
    GPIO_PORTF_LOCK_REG = 0x4C4F434B;
 //   GPIO_PORTF_CR_REG = 0x1F;
    GPIO_PORTF_AMSEL_REG = 0;
    GPIO_PORTF_PCTL_REG = 0x00;
    GPIO_PORTF_AFSEL_REG = 0;
    GPIO_PORTF_DEN_REG |= 0x1F; // Kanet 0x09

    if (dir == INPUT)
    {
        GPIO_PORTF_DIR_REG &= 0xEE; // wla 23ml FE ?? hya kant |=00
    }
    else if (dir == OUTPUT)
    {
        GPIO_PORTF_DIR_REG |= 0x0E;
    }
    else
    {
        printf("Please choose whether this pin is i/p or o/p.\n");
    }
}

void sw_ini() {
    GPIO_PORTF_LOCK_REG = 0x4C4F434B;
    GPIO_PORTF_CR_REG = 0x01;
    GPIO_PORTF_AMSEL_REG = 0;
    GPIO_PORTF_PCTL_REG &= 0xFFFFFFF0;
    GPIO_PORTF_PUR_REG = 0x11;
    GPIO_PORTF_DEN_REG |= 0x1F;
    // hwa b2a el mfrood aktb hna gpio_dir brdk wla a3ml eh
}
#define DELAY_VALUE                         1000000  // found this delay code on a website and used it down below in the code
unsigned long j=0;
void Delay(void){
    for (j=0; j<DELAY_VALUE ; j++);
}

void Delay100ms()  // found it also on another website but its not efficient as the other code.
{
unsigned long i;
i = 1333333;
while(i > 0)
i = i - 1;
}

int main(void)
{
    volatile unsigned long delay = 0;
    SYSCTL_REGCGC2_REG |= 0x20;
    delay = SYSCTL_REGCGC2_REG;
    Initi(OUTPUT);

    sw_ini();


    while(1)
    {
        if(!(GPIO_PORTF_DATA_REG & 0x01) || !(GPIO_PORTF_DATA_REG & 0x10))
        {
            GPIO_PORTF_DATA_REG ^= 0x02 ;
            Delay();
    //        GPIO_PORTF_DATA_REG ^= 0x02 ;
    //        Delay();
    //        GPIO_PORTF_DATA_REG ^= 0x02 ;
    //        Delay();


       //     Delay100ms(1);

        }
        /*else
        {
            GPIO_PORTF_DATA_REG &= ~0x04;
        }*/
      /*  else if ((GPIO_PORTF_DATA_REG & 0x01) || (GPIO_PORTF_DATA_REG & 0x10))
        {
            GPIO_PORTF_DATA_REG &= ~0x04;
        }*/
    }

}
