void forward()
{

  Serial.println("forward------------------------------");
  // analogWrite(pwm_1, 150);
  // analogWrite(pwm_2, 150);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
  digitalWrite(R3, HIGH);
  digitalWrite(R4, LOW);

}

void reverse()
{
  Serial.println("reverse-------------------------------");
  // analogWrite(pwm_1, 150);
  // analogWrite(pwm_2, 150);
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, LOW);
  digitalWrite(R4, HIGH);
}

void right()
{
  Serial.println("right--------------------------");
  // analogWrite(pwm_1, 150);
  // analogWrite(pwm_2, 150);
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  digitalWrite(R4, LOW);
}

void left()
{
  Serial.println("left-------------------------------");
  // analogWrite(pwm_1, 150);
  // analogWrite(pwm_2, 150);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
  digitalWrite(R3, LOW);
  digitalWrite(R4, HIGH);
}
void stop_1()
{
  Serial.println("STOP---------------------------------------");
  // analogWrite(pwm_1, 0);
  // analogWrite(pwm_2, 0);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
  digitalWrite(R3, LOW);
  digitalWrite(R4, LOW);
}


void up_down_motor_up()
{

  digitalWrite(upm1, HIGH);
  digitalWrite(upm2, LOW);


}

void up_down_motor_down()
{
   digitalWrite(upm1, LOW);
  digitalWrite(upm2, HIGH);
}

void up_down_motor_stop()
{
    digitalWrite(upm1, HIGH);
  digitalWrite(upm2, HIGH);
}


void grip_motor_open()
{
  digitalWrite(grm1, HIGH);
  digitalWrite(grm2, LOW);

}

void grip_motor_close()
{
     digitalWrite(grm1, LOW);
  digitalWrite(grm2, HIGH);
}

void grip_motor_stop()
{
  digitalWrite(grm1, HIGH);
  digitalWrite(grm2, HIGH);
}
