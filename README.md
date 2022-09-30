# Cansat-Training-Software
Hussein Hamie software stream training packet
This code takes in a temperature reading and shines an led color and moves a servo to a certain angle based on the tempure read by the sensor.
The code initializes the rgb led via pins 3,5 and 6 and calls in the servo utility assigning the servo through pin 9 as designation Servo. 

In the void loop the reading is taken in as an analog signal and is converted to an integer temperature reading based on the equation specified for this temperature sensor. 
The map function is then used to map the temperature values to servo angles for the servo motor as per the chart given in the assignment outline.
The switch assigns a color value based on the temperature range but entereing the coresponding color values into the setColor function.
