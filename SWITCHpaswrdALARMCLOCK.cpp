# define F_CPU 1000000
#include <avr/io.h>
# include <util/delay.h>
void lcd_init();
void disp_cmd(unsigned int cmd);
void disp_data(int cmd);
void disp_num(unsigned int num);
void disp_string(  char *str);
void special_charringbell1();//2
void special_charringbell2();//3
void special_charringbell3();//4
int disp_key();
int main(void)
{
	DDRA=0X00;
	DDRB=0XFF;
	PORTA=0XFF;
	DDRC = 0XFF;
	DDRD=0X00;
	PORTD=0XFF;

	lcd_init();
	special_charringbell1();//2
	special_charringbell2();//3
	special_charringbell3();//4
	int y=0,k=0;
	int h1,h0,s1,s0,m1,m0;
	float z;
	disp_cmd(0X80);
	disp_string("WELCOME");
	_delay_ms(1000);
	disp_cmd(0X01);
	_delay_ms(2);
	disp_cmd(0X80);
	disp_string("Enter the paswrd");
	
	while (1)
	{
		
		while(k!=8)
		{
			int k=disp_key();
			if (k==0)
			{
				break;
			}
			
			else
			{
				y=(y * 10+k);
				disp_cmd(0XC4);
				disp_num(y);
			}
		}
		if (y==1234)
		{
			disp_cmd(0X01);
			_delay_ms(2);
			disp_cmd(0X80);
			disp_string( "PASSWORD MATCHED");
			_delay_ms(2000);
			disp_cmd(0X01);
			_delay_ms(2);
			  while(1)
			  {
				  start:
				  for(h1=0;h1<=2;h1++)

				  {
					  for(h0=0;h0<=9;h0++)
					  {
						  if(h1==2 && h0==4)
						  {
							  goto start;
						  }
						  for(m1=0;m1<=5;m1++)
						  {
							  for(m0=0;m0<=9;m0++)
							  {
								  
								  
								  
								  for(s1=0;s1<=5;s1++)
								  {
									  for(s0=0;s0<=9;s0++)
									  {
										  
										  
										  for (z=0;z<=9;z++)
										  {
											  
											  disp_cmd(0X80);
											  disp_string ( "ALARM CLOCK");
											  if (  s1==0 && s0==0)
											  {

												  disp_cmd(0X8F);
												  
												  disp_data(2);
												  
												  
												  
												  //disp_cmd(0X01);
												  _delay_ms(2);
												  disp_cmd(0X8F);
												  disp_data(3);
												  _delay_ms(2);
												  //disp_cmd(0X01);
												  _delay_ms(2);
												  disp_cmd(0X8F);
												  disp_data(4);
												  _delay_ms(2);
												  disp_cmd(0X8F);
												  disp_data(' ');
												  
											  }
											  disp_cmd(0XC2);
											  disp_num(h1);
											  _delay_ms(5);
											  disp_cmd(0XC3);
											  disp_num(h0);
											  _delay_ms(5);
											  disp_cmd(0XC5);
											  disp_num(m1);
											  _delay_ms(5);
											  disp_cmd(0XC6);
											  disp_num(m0);
											  _delay_ms(5);
											  disp_cmd(0XC8);
											  disp_num(s1);
											  _delay_ms(5);
											  disp_cmd(0XC9);
											  disp_num(s0);
											  
											  
											  _delay_ms(2);
											  //  disp_cmd(0X01);
											  // _delay_ms(3);
											  
										  }
									  }
								  }
							  }
						  }
					  }
					  
				  }
			  }
			
			
		}
		else{
			disp_cmd(0X01);
			_delay_ms(2);
			disp_cmd(0X80);
			disp_string( "PASSWORD NOT MATCHED");
			_delay_ms(1000);
			disp_string("try again");
			
		}
	}
	
	
	
	return 0;
}
int disp_key()
{
	while (1)
	{
		
		if (PINA==0b11111110)
		{
			while (PINA==0XFE);
			
			
			PORTB=0b00000001;//1
			
			return 1;
			
			
		}
		
		else if (PINA==0b11111101)
		{
			while (PINA==0XFD);
			PORTB=0b00000010;//2
			
			return 2;
		}
		else if (PINA==0b11111011)
		{
			while (PINA==0XFB);
			PORTB=0b00000100;//3
			
			return 3;
		}
		else if (PINA==0b11110111)
		{
			while (PINA==0XF7);
			PORTB=0b00001000;//4
			
			return 4;
		}
		else if (PINA==0b11101111)
		{
			while (PINA==0XEF);
			PORTB=0b00010000;//5
			
			return 5;
		}
		else if (PINA==0b11011111)
		{
			while (PINA==0XDF);
			PORTB=0b00100000;//6
			
			return 6;
		}
		else if (PINA==0b10111111)
		{
			while (PINA==0XBF);
			PORTB=0b01000000;//7
			
			return 7;
		}
		else if (PINA==0b01111111)
		{
			while (PINA==0X7F);
			PORTB=0b10000000;//8
			
			return 8;
		}
		else if (PIND==0b11111110)
		{
			while (PIND==0XFE);
			PORTB=0b00000001;//9
			
			return 9;
		}
		else if (PIND==0b11111101)
		{
			while (PIND==0XFD);
			PORTB=0b00000010;//0
			
			return 0;
		}
		//else if (PIND==0b11111011)
	//	{
		//	while (PINA==0XFB);
		//	PORTB=0b00000100;//0
			
			//return ;
		//}
	}
}

void special_charringbell1()//2
{
	
	
	disp_cmd(0X50);
	disp_data(0X04);
	disp_data(0X0E);
	disp_data(0X11);
	
	disp_data(0X11);
	disp_data(0X11);
	disp_data(0X1F);
	disp_data(0X08);
	
	
	
	
}
void special_charringbell2()//3
{
	disp_cmd(0X58);
	disp_data(0X04);
	disp_data(0X0E);
	disp_data(0X11);
	
	disp_data(0X11);
	disp_data(0X11);
	disp_data(0X1F);
	disp_data(0X04);
}
void special_charringbell3()//4
{
	disp_cmd(0X60);
	disp_data(0X04);
	disp_data(0X0E);
	disp_data(0X11);
	
	disp_data(0X11);
	disp_data(0X11);
	disp_data(0X1F);
	disp_data(0X02);
}
void disp_cmd(unsigned int cmd)
{
	PORTC=((cmd & 0XF0)+0X04);
	_delay_ms(1);
	PORTC=PORTC - 0X04;
	PORTC=(((cmd<<4)& 0XF0)+0X04);
	_delay_ms(1);
	PORTC=PORTC-0X04;
	
}
void disp_data( int cmd)
{
	PORTC=((cmd  & 0XF0)+0X05);
	_delay_ms(1);
	PORTC=PORTC - 0X04;
	PORTC=(((cmd <<4)& 0XF0)+0X05);
	_delay_ms(1);
	PORTC=PORTC-0X04;
	
}

void disp_string( char *str)
{
	int i=0;
	while (str[i]!='\0')
	{
		disp_data (str[i]);
		i++;
		
	}
}

void disp_num(unsigned int num)
{
	int a=0;
	if (num==0)
	{
		disp_data(48);
	}
	disp_cmd (0X04);
	while (num!=0)
	{
		a=num % 10;
		disp_data(a+48);
		num=num/10;
	}
}
void lcd_init()
{
	disp_cmd(0X02);
	disp_cmd(0X28);
	disp_cmd(0X0C);
	disp_cmd(0X06);
}