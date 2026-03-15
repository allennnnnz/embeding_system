#include <reg51.h>

sbit LED = P1^0; //把port1.0取做LED
void delay(unsigned int t)
{
    unsigned int i,j;
    for(i=0;i<t;i++)
        for(j=0;j<120;j++);
}

//給一個ratio就會在固定週期內量ratio %的時間亮，剩下的時間暗
void pwm(unsigned int ratio)
{
    unsigned char k;
    for(k=0;k<100;k++)
    {
        if(k<ratio)
            LED = 1;
        else
            LED = 0;
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
            //讓同一個亮度維持久一點
            for(k=0;k<10;k++)
                pwm(i);
            delay(10);
        }

        // 漸暗
        for(i=100;i>1;i--)
        {
            //讓同一個亮度維持久一點
            for(k=0;k<10;k++)
                pwm(i);
            delay(10);
        }
    }
}