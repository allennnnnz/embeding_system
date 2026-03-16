/* CLED.C for LED */
/* 20150928 §ùÃY «J¤¤Åv */

#include"reg51.h"
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
void breath()
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
//void delay(unsigned char s);
void main()
{
	unsigned char LED;
    //LED燈初始狀態為0000 0001，P1口初始狀態為1111 1110
	LED=0x01;
	P1=0xfe;
    //延遲一段時間後，LED燈從右向左移動
	while(1)
	{
		breath();
		LED=LED<<1;
		if (LED == 0)
		{
		 	LED = 0x01;
		}
		P1=~LED;
	}
}

void delay(unsigned int s)
{
	unsigned int m;
	for(m=0;m<s;m++);
}

