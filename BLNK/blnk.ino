BLYNK_WRITE(V9)
{
  int button = param.asInt(); // read button
  button_1 = button;
  Serial.print("Button");
  Serial.println(button_1);
}

BLYNK_WRITE(V10)
{
  int button = param.asInt(); // read button
  python_int = button;
  Serial.print("python_int : ");
  Serial.println(python_int);
}
BLYNK_WRITE(V11)
{
  String button = param.asStr(); // read button
  receivepython = button;
  Serial.print("receivepython : ");
  Serial.println(receivepython);

  // ==================== AI SAFETY LAYER (ADDED) ====================
  // Python (YOLOv8n on laptop) writes "STOP" or "GO" to V11.
  // This sets the global aiStop flag checked at the top of loop().
  if(receivepython == "STOP")
  {
    aiStop = true;
  }
  else if(receivepython == "GO")
  {
    aiStop = false;
  }
  // ===================================================================
}


void receive_()
{

while (Serial2.available()>0) {
    // get the new byte:
    inChar = (char)Serial2.read();
    a_receved[m_receved] = inChar;
    if (a_receved[0] == '*') 
    {
     if (m_receved <= 12) {
     m_receved++;
     }
    }
  }
  m_receved = 5;
  if (m_receved > 1)
  { 
    val1= (a_receved[1]-0x30)*100 + (a_receved[2]-0x30)*10  + (a_receved[3] - 0x30);delay(100);
    val2= (a_receved[4]-0x30)*100 + (a_receved[5]-0x30)*10  + (a_receved[6] - 0x30);delay(100);
    val3= (a_receved[7]-0x30)*100 + (a_receved[8]-0x30)*10  + (a_receved[9] - 0x30);delay(100);
    val4= (a_receved[10]-0x30)*100 + (a_receved[11]-0x30)*10  + (a_receved[12] - 0x30);delay(100);
    // val5= (a_receved[13]-0x30)*100 + (a_receved[14]-0x30)*10  + (a_receved[15] - 0x30);delay(100);
    //  val6= (a_receved[16]-0x30)*100 + (a_receved[17]-0x30)*10  + (a_receved[18] - 0x30);delay(100);
    //   val7= (a_receved[19]-0x30)*100 + (a_receved[20]-0x30)*10  + (a_receved[21] - 0x30);delay(100);
    m_receved = 0;
  }

}

BLYNK_WRITE(V0)
{
  int button = param.asInt(); // read button
  if (button == 1)
  {

        forward();

  }

}
BLYNK_WRITE(V1)
{
  int button = param.asInt(); // read button
  if (button == 1)
  {


    reverse();

  }

}
BLYNK_WRITE(V2)
{
  int button = param.asInt(); // read button
  if (button == 1)
  {
left();
    

  }

}
BLYNK_WRITE(V3)
{
  int button = param.asInt(); // read button
  if (button == 1)
  {

    right();
    
  }

}
BLYNK_WRITE(V4)
{
  int button = param.asInt(); // read button
  if (button == 1)
  {
    stop_1();
  }

}
