#include <Servo.h>

// C++ code
//

// RGB LED pin setup
int red = 3;
int blue = 5;
int green = 6;

//Servo Setups

Servo servo;
int pos;


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

  pos = temperatureC + 40; //used to offest negative values in order to rotate servo
  
  
  switch (temperatureC) {
  case -40 ... -10: //Blue
    setColor(0,0,255);
    servo.write(pos);
    break;
  case -9 ... 20:  //Green
    setColor(0,255,0);
    servo.write(pos);
    break;
  case 21 ... 50:  //Yellow
    setColor(255,255,0);
    servo.write(pos);
    break;
  case 51 ... 80:  //Purple
    setColor(170,0,255);
    servo.write(pos);
    break;
  case 81 ... 110:  //Red
    setColor(255,0,0);
    servo.write(pos);
    break;
  case 111 ... 125: //White
    setColor(255,255,255);
    servo.write(pos);
    break;
	}
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(red, redValue);
  analogWrite(green, greenValue);
  analogWrite(blue, blueValue);
}