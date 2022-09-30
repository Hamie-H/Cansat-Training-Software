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

}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(red, redValue);
  analogWrite(green, greenValue);
  analogWrite(blue, blueValue);
}