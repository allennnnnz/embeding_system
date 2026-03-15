/* CLED.C for LED */
/* 20150928 §ùÃY «J¤¤Åv */

#include"reg51.h"
void delay(unsigned int s);
//void delay(unsigned char s);
void main()
{
	unsigned char LED;
	LED=0x01;
	P1=0xfe;
	while(1)
	{
		delay(8000);
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

