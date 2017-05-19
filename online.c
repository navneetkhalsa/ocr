
#include<reg51.h>
#include"lcd.h"
#include"uart.h"

void main()
{
	unsigned char a,i,read[15];
	lcd_init();
	uart_init();
	lcd_string("GSM interfacing");
	while(1)
	{
		
		while(rx_data()!=0x0d);
		
			while(rx_data()!=0x0a);
			
				if(rx_data()=='+')
				{
					if(rx_data()=='C')
					{
						if(rx_data()=='M')
						{
							if(rx_data()=='T')
							{
								if(rx_data()=='I')
								{
								while(rx_data()!=',');
									a=rx_data();
									delay_ms(10);
									tx_string("at");
									tx_data(0x0d);
									tx_data(0x0a);
									tx_string("at+cmgf=1");
									tx_data(0x0d);
									tx_data(0x0a);
									tx_string("at+cmgr=");
									tx_data(a);
									tx_data(0x0d);
									tx_data(0x0a);
									
									while(rx_data()!=0x0a);
									while(rx_data()!=0x0a);
									while(rx_data()!=0x0a);
									
									for(i=0;i<15;i++)
									{
										read[i]=rx_data();
									}
									lcd_stringxy(1,0,read);
									
								}}}}}}}	