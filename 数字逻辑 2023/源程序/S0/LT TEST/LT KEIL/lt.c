#include <reg52.h>
sbit led1=P1^0;
sbit led2=P1^1;

void delay(unsigned int n)
{
	unsigned char i;
	while (--n)
	 for (i=0;i<125;i++);
}

void main()
{	
	while(1)
	{
		led1=0;
		led2=1;
		delay(100);
		led1=1;
		led2=0;
		delay(1000);
	}
}