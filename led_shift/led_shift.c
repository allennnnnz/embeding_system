/* CLED.C for LED */
/* 20150928 §ùÃY «J¤¤Åv */

#include"reg51.h"
void delay(unsigned int s);
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

