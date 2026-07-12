#include <Servo.h>


Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
 
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
}

void loop() {
  
  unsigned long currentTime = millis();
  
  
  if (currentTime < 2000) {
    
    for (int pos = 0; pos <= 180; pos += 2) { 
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      servo4.write(pos);
      delay(10); 
    }
    
    for (int pos = 180; pos >= 0; pos -= 2) { 
      servo1.write(pos);
      servo2.write(pos);
      servo3.write(pos);
      servo4.write(pos);
      delay(10);
    }
  } 
  
  else {
    servo1.write(90);
    servo2.write(90);
    servo3.write(90);
    servo4.write(90);
  }
}