#include <LCD_I2C.h>
LCD_I2C lcd(0x27  );





int trigPin1 = 5;    // Trigger
int echoPin1 = 18;    // Echo
long duration1, front_ultrasoni_value, inches1;

int trigPin2 = 19;    // Trigger
int echoPin2 = 23;    // Echo
long duration2, back_ultrasoni_value, inches2;

#define ir_1 13
#define ir_2 14

int ir1,ir2;



#define RXD2 16  // RX pin for Serial2
#define TXD2 17  // TX pin for Serial2


void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(ir_1, INPUT);
  pinMode(ir_2, INPUT);

  lcd.begin(); 
  lcd.backlight();
  lcd.setCursor(0,0); 
  lcd.print("TRASH  "); // You can make spaces using well... spaces
  lcd.setCursor(0,1); // Or setting the cursor in the desired position.
  lcd.print("COLLECTION   ");
  delay(3000);
  lcd.clear();


}

void loop() 
{

ir1=digitalRead(ir_1);
ir2=digitalRead(ir_2);

front_ultrasonic();
back_ultrasoni();
Serial.print("back_ultrasoni_value : ");
Serial.println(back_ultrasoni_value);
Serial.print(" front_ultrasoni_value : ");
Serial.println( front_ultrasoni_value);

Serial.print("ir1----------------- : ");
Serial.println(ir1);
Serial.print(" ir2 -------------------: ");
Serial.println( ir2);



lcd.setCursor(0, 0);
lcd.print("D1:");
if(front_ultrasoni_value <=9){lcd.print("00");lcd.print(front_ultrasoni_value  );}
else if(front_ultrasoni_value  <=99){lcd.print("0");lcd.print(front_ultrasoni_value  );}
else if(front_ultrasoni_value  <=999){lcd.print("");lcd.print(front_ultrasoni_value  );}


lcd.setCursor(9, 0);
lcd.print("D2:");
if(back_ultrasoni_value <=9){lcd.print("00");lcd.print(back_ultrasoni_value  );}
else if(back_ultrasoni_value  <=99){lcd.print("0");lcd.print(back_ultrasoni_value  );}
else if(back_ultrasoni_value  <=999){lcd.print("");lcd.print(back_ultrasoni_value );}


senddata();

delay(500);
}


  void front_ultrasonic()
 { 
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  pinMode(echoPin1, INPUT);
  duration1 = pulseIn(echoPin1, HIGH);
 
  // Convert the time into a distance
 front_ultrasoni_value= (duration1/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches1 = (duration1/2) / 74; 
  front_ultrasoni_value=map(front_ultrasoni_value,0,17,100,0);

  if(front_ultrasoni_value<=0)
  {
front_ultrasoni_value=0;
  }
  
 }
  void back_ultrasoni()
{
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  pinMode(echoPin2, INPUT);
  duration2 = pulseIn(echoPin2, HIGH);
 
  // Convert the time into a distance
    back_ultrasoni_value = (duration2/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches2 = (duration2/2) / 74; 
 back_ultrasoni_value=map(back_ultrasoni_value,0,20,100,0);

  if(back_ultrasoni_value<=0)
  {
back_ultrasoni_value=0;
  }
  
}
void senddata()
{
//lora


  
 Serial2.print('*');

  
//1
 if(front_ultrasoni_value <= 9){ Serial2.print("00"); Serial2.print(front_ultrasoni_value);}
 else if(front_ultrasoni_value<= 99){ Serial2.print("0"); Serial2.print(front_ultrasoni_value);}
 else if(front_ultrasoni_value <= 999){ Serial2.print(front_ultrasoni_value);}

////2
 if( back_ultrasoni_value <= 9){ Serial2.print("00"); Serial2.print( back_ultrasoni_value);}
 else if( back_ultrasoni_value <= 99){ Serial2.print("0"); Serial2.print( back_ultrasoni_value);}
 else if( back_ultrasoni_value <= 999){ Serial2.print( back_ultrasoni_value);}


//4
   if( ir1 <= 9){ Serial2.print("00"); Serial2.print( ir1);}
 else if( ir1 <= 99){ Serial2.print("0"); Serial2.print( ir1);}
 else if( ir1 <= 999){ Serial2.print( ir1);}
//5
 if( ir2 <= 9){ Serial2.print("00"); Serial2.print( ir2);}
else if( ir2 <= 99){ Serial2.print("0"); Serial2.print( ir2);}
 else if( ir2 <= 999){ Serial2.print( ir2);}


}
