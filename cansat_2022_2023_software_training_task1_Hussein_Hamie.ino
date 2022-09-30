#include <Servo.h>

// C++ code
//

// RGB LED pin setup
int red = 3;
int blue = 5;
int green = 6;

//Servo Setups

Servo servo;

void setup()
{
	
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  
  servo.attach(9);
}


void loop(){
  int reading = analogRead(A0);
  float voltage = reading * (5.0 / 1024.0);
  int temperatureC = (voltage - 0.5) * 100;

  float angle = map(temperatureC, -40, 125, 0 , 180);
  servo.write(angle);
  
  switch (temperatureC) {
  case -40 ... -10: //Blue
    setColor(0,0,255);
    break;
  case -9 ... 20:  //Green
    setColor(0,255,0);
    break;
  case 21 ... 50:  //Yellow
    setColor(255,255,0);
    break;
  case 51 ... 80:  //Purple
    setColor(170,0,255);
    break;
  case 81 ... 110:  //Red
    setColor(255,0,0);
    break;
  case 111 ... 125: //White
    setColor(255,255,255);
    break;
	}
  
  
  
  

}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(red, redValue);
  analogWrite(green, greenValue);
  analogWrite(blue, blueValue);
}