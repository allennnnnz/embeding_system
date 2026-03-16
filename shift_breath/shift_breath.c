/* CLED.C for LED */
/* fixed version */

#include "reg51.h"

void delay(unsigned int t)
{
    unsigned int i,j;
    for(i=0;i<t;i++)
        for(j=0;j<30;j++);
}

/* PWM 控制 LED 亮度 */
void pwm(unsigned char ratio, unsigned char LED)
{
    unsigned char k;

    if(ratio > 100)
        ratio = 100;

    for(k=0;k<100;k++)
    {
        if(k < ratio)
        {
            P1 &= ~LED;   // LED ON (Active Low)
        }
        else
        {
            P1 |= LED;    // LED OFF
        }

     
    }
}

/* 呼吸效果 */
void breath(unsigned char LED)
{
    unsigned char i;
    unsigned char k;

    // 漸亮
    for(i=1;i<=100;i++)
    {
        for(k=0;k<30;k++)
            pwm(i, LED);
    }

    // 漸暗
    for(i=100;i>=1;i--)
    {
        for(k=0;k<30;k++)
            pwm(i, LED);
    }
}

void main()
{
    unsigned char LED = 0x01;

    P1 = 0xFF;   // LED 全部關

    while(1)
    {
        breath(LED);

        LED = LED << 1;

        if(LED == 0x10)
            LED = 0x01;
    }
}