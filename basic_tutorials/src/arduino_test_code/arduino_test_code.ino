#include<Servo.h>
#define WRITE_PERIOD 500 //ms

class Angle
{
public:
  void updateAngle(){angle_ = (long)analogRead(A0)*180/1024 - home_;}
  int getAngle(){return angle_;}
  void setHome(int h){home_ = h;}  
private:
  int angle_ = 0;
  int home_ = 0;
};


Servo servo;
Angle ang;


int serial_in = {};
int angle = 0;

unsigned int ms_timer = 0;

void setup() 
{
  servo.attach(9);  
  Serial.begin(115200);
}

void loop() 
{
  ang.updateAngle(); 
  
  servo.write(ang.getAngle());
  
  if(Serial.available()){
    serial_in = Serial.parseInt();
    ang.setHome(serial_in);
  }

  if(ms_timer > WRITE_PERIOD){  
    Serial.write(ang.getAngle());
    ms_timer = 0;
  }
  
  ms_timer++;
  delay(1);
}
