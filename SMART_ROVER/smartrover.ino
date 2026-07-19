//e4577iot@web-library.net
//Info@2026

#define IR_LEFT 36
#define IR_RIGHT 39

#define BLYNK_TEMPLATE_ID "TMPL3W-obI5OG"
#define BLYNK_TEMPLATE_NAME "Trash Collection"
#define BLYNK_AUTH_TOKEN "A5Z4IDP_GXy94PJLwlHB5ZZe7fS4vmmu"

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "IOT";
char pass[] = "123456789";
char auth[] = BLYNK_AUTH_TOKEN;

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#include <LCD_I2C.h>
LCD_I2C lcd(0x27);

unsigned char a_receved[100];
unsigned int val1,val2,val3,val4,val5,val6,val7;
unsigned int m_receved = 0;
unsigned char a1 = 0, a2 = 0, a3 = 0, a4 = 0;
char inChar;

float temp_final;
int button_1,python_int;

String  receivepython;

#define RXD2 16  // RX pin for Serial2
#define TXD2 17  // TX pin for Serial2

#define R1 13
#define R2 12
#define R3 14
#define R4 27

#define upm1 15
#define upm2 4

#define grm1 5
#define grm2 18

#define IR_LEFT 26
#define IR_RIGHT 25

int bio,non_bio,act=0,act_2=0;

// ==================== AI SAFETY LAYER (ADDED) ====================
// Set true when Python/YOLOv8 sends "STOP" on Blynk V11, false on "GO".
// See Communication.ino -> BLYNK_WRITE(V11)
bool aiStop = false;
// ===================================================================

void setup() 
{




Serial.begin(9600);

  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);





 Serial.print("setup : ");

 Serial.print("setup 1 : ");

lcd.begin(); 
lcd.backlight();
lcd.setCursor(0,0); 
lcd.print("TRASH  "); // You can make spaces using well... spaces
lcd.setCursor(0,1); // Or setting the cursor in the desired position.
lcd.print("COLLECTION   ");

  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);

   pinMode(upm1, OUTPUT);
  pinMode(upm2, OUTPUT);

   pinMode(grm1, OUTPUT);
  pinMode(grm2, OUTPUT);

  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);

up_down_motor_stop();grip_motor_stop();

   Serial.print("setup4 : ");
 Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);  // ADDED: enable Blynk connection
 Serial.print("setup5 : ");
lcd.clear();
 Serial.print("setup6 : ");


}

void loop() 
{
  Blynk.run();  // ADDED: process Blynk cloud events (dashboard buttons + Python AI STOP/GO)

  // ==================== AI SAFETY LAYER (ADDED) ====================
  // If Python/YOLOv8 has sent STOP (aiStop == true), pause immediately:
  // stop the drive motors, keep receiving Serial2/LoRa data so no state
  // is lost, and skip line following + arm/grip logic entirely for this
  // pass through loop(). Nothing is reset - when GO arrives, aiStop goes
  // false and the code below resumes exactly where it left off.
  if(aiStop)
  {
    stop_1();
    receive_();
    delay(500);
    return;
  }
  // ===================================================================

Serial.print("val 1 : ");
Serial.println(val1);


Serial.print("val 12 : ");
Serial.println(val2);



Serial.print("val 3: ");
Serial.println(val3);



Serial.print("val 4 : ");
Serial.println(val4);

    int leftIR  =  analogRead(IR_LEFT);
  int rightIR =  analogRead(IR_RIGHT);


Serial.print("leftIR: ");
Serial.println(leftIR);

Serial.print("rightIR: ");
Serial.println(rightIR);


lcd.setCursor(0, 0);
lcd.print("D1:");
if(val1 <=9){lcd.print("00");lcd.print(val1  );}
else if(val1  <=99){lcd.print("0");lcd.print(val1  );}
else if(val1  <=999){lcd.print("");lcd.print(val1  );}


lcd.setCursor(9, 0);
lcd.print("D2:");
if(val2 <=9){lcd.print("00");lcd.print(val2  );}
else if(val2  <=99){lcd.print("0");lcd.print(val2  );}
else if(val2  <=999){lcd.print("");lcd.print(val2 );}

if(val1>=60&&val1<=100&&act==0)
{
   if (leftIR >=10  && leftIR <=4093 && rightIR >=10  && rightIR <=4093) forward();
    else if (leftIR >=10  && leftIR <=4093 && rightIR >= 4094 ) right();
    else if (leftIR >=4094 && rightIR >=10  && rightIR <=4093) left();
    else if (leftIR >=4094 && rightIR >=4094 ) stop_1();

bio=1;


}

if(bio==1)
{
  if(val3==0)
  {
    act=1;

    stop_1();
    up_down_motor_down();
    delay(4000);
 up_down_motor_stop();
       delay(1000);

 
      grip_motor_close();
     delay(4000);
     grip_motor_stop();

      delay(4000);

     up_down_motor_up();
      delay(4000);
       grip_motor_stop();
          delay(3000);
 up_down_motor_down();
     delay(4000);
 up_down_motor_stop();
      delay(1000);
 grip_motor_open();
     delay(4000);
       grip_motor_stop();
            delay(1000);

      up_down_motor_up();  
            delay(4000); 
       up_down_motor_stop();
       bio=0;
act=0;
  }
}
    


   if(val2>=60&&val2<=100&&act_2==0)
{
   if (leftIR >=10  && leftIR <=4093 && rightIR >=10  && rightIR <=4093) forward();
    else if (leftIR >=10  && leftIR <=4093 && rightIR >= 4094 ) right();
    else if (leftIR >=4094 && rightIR >=10  && rightIR <=4093) left();
    else if (leftIR >=4094 && rightIR >=4094 ) stop_1();

non_bio=1;


}




if(non_bio==1)
{
  if(val4==0)
  {
    act_2=1;

    stop_1();
    up_down_motor_down();
    delay(4000);
 up_down_motor_stop();
       delay(1000);

 
      grip_motor_close();
     delay(4000);
     grip_motor_stop();

      delay(4000);

     up_down_motor_up();
      delay(4000);
       grip_motor_stop();
             delay(3000);
 up_down_motor_down();
     delay(4000);
 up_down_motor_stop();
      delay(1000);
 grip_motor_open();
     delay(4000);
       grip_motor_stop();
            delay(1000);

      up_down_motor_up();  
            delay(4000); 
       up_down_motor_stop();
       non_bio=0;
act_2=0;
  }
}

if(button_1==1)
{


Blynk.virtualWrite(V5,val1);//ultra
Blynk.virtualWrite(V6,val2);//x
Blynk.virtualWrite(V7,val3);//y
Blynk.virtualWrite(V8,val4);//z
// Blynk.virtualWrite(V2,val5);//limit
// Blynk.virtualWrite(V1,val6);//vib
// Blynk.virtualWrite(V6,val7);//speed

//Blynk.virtualWrite(V9,s);//speed

}


receive_();
delay(500);
}
