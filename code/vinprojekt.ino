#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
byte stopinje[8] =
              {
                0b00111,
                0b00101,
                0b00111,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000
              };
byte happy[8] =
              {
                0b00000,
                0b00000,
                0b10001,
                0b00000,
                0b10001,
                0b11111,
                0b00000,
                0b00000
              };
byte meh[8] =
              {
                0b00000,
                0b00000,
                0b10001,
                0b00000,
                0b00000,
                0b11111,
                0b00000,
                0b00000
              };
byte sad[8] =
              {
                0b00000,
                0b00000,
                0b10001,
                0b00000,
                0b11111,
                0b10001,
                0b00000,
                0b00000
              };
int vhod=11;
volatile unsigned long len = 0;
unsigned char value = 0;
unsigned sum = 0;
unsigned char x[5];
unsigned int y[40];
int z=0;
void setup()
{
 lcd.init();
 lcd.init();
 lcd.backlight();
 lcd.print("Temperatura=");
 lcd.setCursor(0,1);
 lcd.print("   Vlaznost= ");
 lcd.createChar(1, stopinje);
 lcd.createChar(2, meh);
 lcd.createChar(3, happy);
 lcd.createChar(4, sad);
 lcd.setCursor(14,0);
 lcd.write(1);
 lcd.print("C");
 lcd.setCursor(14,1);
 lcd.print("%");
}

void loop()
{

 delay(100);
 while(1)
 {
  delay(100);
  pinMode(vhod,OUTPUT);
  digitalWrite(vhod,LOW);
  delay(20);
  digitalWrite(vhod,HIGH);
  pinMode(vhod,INPUT_PULLUP);

  len=pulseIn(vhod, LOW);
  if(len <= 84 && len >= 72)
  {
      while(1)
      {
        len=pulseIn(vhod, HIGH);

        if(len <= 26 && len >= 20){
        value=0;}

        else if(len <= 74 && len >= 65){
        value = 1;}

        else if(z == 40){
        break;}

        x[z/8]|= value << (7 - (z%8));
        y[z] = value;
        z++;
      }
    }
sum=x[0]+x[1]+x[2]+x[3];

if(sum==x[4] && sum!=0)
{
lcd.setCursor(12,0);
lcd.print(x[2]);
lcd.setCursor(12,1);
lcd.print(x[0]);

if(x[2] < 20 && x[2] > 15){
lcd.setCursor(0,1);
lcd.write(2);
}
else if(x[2] < 33 && x[2] > 19){
lcd.setCursor(0,1);
lcd.write(3);
}
else if(x[2] < 16){
lcd.setCursor(0,1);
lcd.write(4);
}
else if(x[2] > 32 && x[2] < 40){
lcd.setCursor(0,1);
lcd.write(2);
}
else if(x[2] > 39){
lcd.setCursor(0,1);
lcd.write(4);
}

}

z=0;
x[0] = x[1] = x[2] = x[3] = x[4] = 0;
 }
}
