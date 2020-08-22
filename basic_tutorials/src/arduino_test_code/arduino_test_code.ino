#include<Servo.h>

Servo servo;

void setup()
{
  servo.attach(9);
  Serial.begin(115200);
}

void loop()
{
  if (Serial.available()) {    
    servo.write(Serial.parseInt());
    Serial.print(analogRead(A0));
  }
}
