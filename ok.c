
#include <mega16.h>
#include <alcd.h>
#include <delay.h>

char keypad();

void main(void)
{
    int x1 = 0;
    int count = 0;

	DDRC = 0b00000111;
	PORTC = 0b11111000;
	lcd_init(16);
    
	while (1)
		{
             
            x1 = keypad();
            lcd_printf("%d",x1);
            count++;  
            	if(count == 32){ 
                lcd_printf("%d",x1);    
                delay_ms(100);
                lcd_clear();    

                }
		}
}

char keypad()
{
	while(1)
		{
            PORTC.0 = 0; PORTC.1 = 1; PORTC.2 = 1;
            //Only C1 is activated
            switch(PINC)
            {
                case 0b11110110:
                while (PINC.3 == 0);
                return 1;
                break;
                
                case 0b11101110:
                while (PINC.4 == 0);
                return 4;
                break;
                
                case 0b11011110:
                while (PINC.5 == 0);
                return 7;
                break;
                
                
            }
            PORTC.0 = 1; PORTC.1 = 0; PORTC.2 = 1;
            //Only C2 is activated
            switch(PINC)
            {
                case 0b11110101:
                while (PINC.3 == 0);
                return 2;
                break;
                
                case 0b11101101:
                while (PINC.4 == 0);
                return 5;
                break;
                
                case 0b11011101:
                while (PINC.5 == 0);
                return 8;
                break;
                
                case 0b10111101:
                while (PINC.6 == 0);
                return 0;
                break;
                
            }
            PORTC.0 = 1; PORTC.1 = 1; PORTC.2 = 0;
            //Only C3 is activated
            switch(PINC)
            {
                case 0b11110011:
                while (PINC.3 == 0);
                return 3;
                break;
                
                case 0b11101011:
                while (PINC.4 == 0);
                return 6;
                break;
                
                case 0b11011011:
                while (PINC.5 == 0);
                return 9;
                break;
                
                
            }  
        
        }
}