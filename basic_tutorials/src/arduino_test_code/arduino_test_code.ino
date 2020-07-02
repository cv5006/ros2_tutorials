#define WRITE_PERIOD 500 //ms

int recieved_data = 0;
unsigned int ms_timer = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if(Serial.available()){
    recieved_data = Serial.parseInt();
  }

  if(ms_timer > WRITE_PERIOD){
    Serial.write(recieved_data);
    ms_timer = 0;
  }
  
  ms_timer++;
  delay(1);
}
