#include <reg51.h>

sbit LED = P1^0;

void delay(unsigned int t)
{
    unsigned int i,j;
    for(i=0;i<t;i++)
        for(j=0;j<120;j++);
}

void pwm(unsigned int ratio)
{
    unsigned char k;
    for(k=0;k<100;k++)
    {
        if(k<ratio)
            P1 = ~0x01;
        else
            P1 = ~0x00;
    }
}

void main()
{
    unsigned int i;
    unsigned int k;

    while(1)
    {
        // 漸亮
        for(i=1;i<100;i++)
        {
            for(k=0;k<10;k++)
                pwm(i);
            delay(10);
        }

        // 漸暗
        for(i=100;i>1;i--)
        {
            for(k=0;k<10;k++)
                pwm(i);
            delay(10);
        }
    }
}