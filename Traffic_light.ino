/*
 Name:		Traffic_light.ino
 Created:	15/03/2023 22:56:43 PM
 Author:	NSH
*/
#include <LiquidCrystal.h>
#define segA PB10
#define segB PB11
#define segC PB15
#define segD PB13
#define segE PB14
#define segF PB1
#define segG PB12

#define control_led1 PA5
#define control_led2 PA4
#define control_led3 PA9
#define control_led4 PA8

#define Led_do PA6
#define Led_vang PA7
#define Led_xanh PA10


#define Led_do1 PA11
#define Led_vang1 PA12
#define Led_xanh1 PA15

#define button PB9

byte counter = 0;

unsigned char digits[] = { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90 };

LiquidCrystal lcd(PC13,PC14,PC15,PA0,PA1,PA2,PA3);
// the setup function runs once when you press reset or power the board
void displayDigit_tens(int digit)
{
	// Mảng chứa các giá trị để hiển thị trên LED 7-segment
	

	// Tách số hàng chục
	int tens = digit / 10;
	// Hiển thị số hàng chục

	digitalWrite(segA, bitRead(digits[tens], 0));
	digitalWrite(segB, bitRead(digits[tens], 1));
	digitalWrite(segC, bitRead(digits[tens], 2));
	digitalWrite(segD, bitRead(digits[tens], 3));
	digitalWrite(segE, bitRead(digits[tens], 4));
	digitalWrite(segF, bitRead(digits[tens], 5));
	digitalWrite(segG, bitRead(digits[tens], 6));
}
void displayDigit_unit(int digit)
{
	// Mảng chứa các giá trị để hiển thị trên LED 7-segment

	// Tách số số đơn vị
	int units = digit % 10;
	// Hiển thị số hàng chục

	digitalWrite(segA, bitRead(digits[units], 0));
	digitalWrite(segB, bitRead(digits[units], 1));
	digitalWrite(segC, bitRead(digits[units], 2));
	digitalWrite(segD, bitRead(digits[units], 3));
	digitalWrite(segE, bitRead(digits[units], 4));
	digitalWrite(segF, bitRead(digits[units], 5));
	digitalWrite(segG, bitRead(digits[units], 6));
}


void setup() 
{
	lcd.begin(16,2);
	pinMode(segA, OUTPUT);
	pinMode(segB, OUTPUT);
	pinMode(segC, OUTPUT);
	pinMode(segD, OUTPUT);
	pinMode(segE, OUTPUT);
	pinMode(segF, OUTPUT);
	pinMode(segG, OUTPUT);

	pinMode(control_led1, OUTPUT);
	pinMode(control_led2, OUTPUT);
	pinMode(control_led3, OUTPUT);
	pinMode(control_led4, OUTPUT);

	pinMode(Led_do,OUTPUT);
	pinMode(Led_vang, OUTPUT);
	pinMode(Led_xanh, OUTPUT);

	pinMode(Led_do1, OUTPUT);
	pinMode(Led_vang1, OUTPUT);
	pinMode(Led_xanh1, OUTPUT);

	pinMode(button, INPUT);

	digitalWrite(Led_do,HIGH);
	digitalWrite(Led_vang, HIGH);
	digitalWrite(Led_xanh, HIGH);

	digitalWrite(Led_do1, HIGH);
	digitalWrite(Led_vang1, HIGH);
	digitalWrite(Led_xanh1, HIGH);

	digitalWrite(control_led1, HIGH);
	digitalWrite(control_led2, HIGH);
	digitalWrite(control_led3, HIGH);
	digitalWrite(control_led4, HIGH);

	attachInterrupt(digitalPinToInterrupt(button), Start, FALLING);
	lcd.setCursor(3, 0);
	lcd.print("PROJECT VXL"); // Prints "Arduino" on the LCD 
	lcd.setCursor(3, 1); // Sets the location at which subsequent text written to the LCD will be displayed 
	lcd.print("NHOM A PLUS");
}

// the loop function runs over and over again until power down or reset
void loop() 
{
	int i, j = 0;
		lcd.clear();
		lcd.setCursor(3, 0);
		lcd.print("CHU Y"); // Prints "Arduino" on the LCD 
		lcd.setCursor(3, 1); // Sets the location at which subsequent text written to the LCD will be displayed 
		lcd.print("CHE DO AUTO");
		delay(2);
		if (counter == 1)
		{
			for (i = 30; i > 3; i--)
			{
				digitalWrite(Led_do, LOW);
				digitalWrite(Led_xanh1, LOW);
				for (j = 0; j < 500; j++)
				{

					digitalWrite(control_led1, LOW);
					digitalWrite(control_led3, LOW);
					displayDigit_tens(i);
					digitalWrite(control_led2, HIGH);
					digitalWrite(control_led4, HIGH);
					delay(1);

					digitalWrite(control_led2, LOW);
					digitalWrite(control_led4, LOW);
					displayDigit_unit(i);
					digitalWrite(control_led1, HIGH);
					digitalWrite(control_led3, HIGH);
					delay(1);
				}

			}
			digitalWrite(Led_xanh1, HIGH);
			for (i = 3; i >= 0; i--)
			{
				digitalWrite(Led_do, LOW);
				digitalWrite(Led_vang1, LOW);
				for (j = 0; j < 500; j++)
				{
					digitalWrite(control_led1, LOW);
					digitalWrite(control_led3, LOW);
					displayDigit_tens(0);
					digitalWrite(control_led2, HIGH);
					digitalWrite(control_led4, HIGH);
					delay(1);

					digitalWrite(control_led2, LOW);
					digitalWrite(control_led4, LOW);
					displayDigit_unit(i);
					digitalWrite(control_led1, HIGH);
					digitalWrite(control_led3, HIGH);
					delay(1);
				}
			}
			digitalWrite(Led_do, HIGH);
			digitalWrite(Led_vang1, HIGH);

			//chu ki 2
			for (i = 30; i > 3; i--)
			{

				for (j = 0; j < 500; j++)
				{

					digitalWrite(control_led1, LOW);
					digitalWrite(control_led3, LOW);
					displayDigit_tens(i);
					digitalWrite(control_led2, HIGH);
					digitalWrite(control_led4, HIGH);
					delay(1);

					digitalWrite(control_led2, LOW);
					digitalWrite(control_led4, LOW);
					displayDigit_unit(i);
					digitalWrite(control_led1, HIGH);
					digitalWrite(control_led3, HIGH);
					delay(1);
				}
				digitalWrite(Led_do1, LOW);
				digitalWrite(Led_xanh, LOW);
			}
			digitalWrite(Led_xanh, HIGH);
			for (i = 3; i >= 0; i--)
			{
				digitalWrite(Led_do1, LOW);
				digitalWrite(Led_vang, LOW);
				for (j = 0; j < 500; j++)
				{
					digitalWrite(control_led1, LOW);
					digitalWrite(control_led3, LOW);
					displayDigit_tens(0);
					digitalWrite(control_led2, HIGH);
					digitalWrite(control_led4, HIGH);
					delay(1);

					digitalWrite(control_led2, LOW);
					digitalWrite(control_led4, LOW);
					displayDigit_unit(i);
					digitalWrite(control_led1, HIGH);
					digitalWrite(control_led3, HIGH);
					delay(1);
				}
			}
			digitalWrite(Led_do1, HIGH);
			digitalWrite(Led_vang, HIGH);
		}
		
}

void Start()
{
	// count  = 1 là start
	// count  = 0 là dừng
	counter++;
	if (counter == 2)
	{
		counter = 0;
	}
}
