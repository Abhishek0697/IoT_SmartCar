/* Rain Sensing Automatic Car Wiper.
This Example includes a SG 90 Servo Motor to Control the Wiper */

#include <Servo.h>
int servoPin =6;   //Servo Control Pin
Servo ServoDemo;
void setup() 
{
ServoDemo.attach(servoPin);
pinMode(A0,INPUT);  //Connect Analog Output of Rain Sensor to pin A0 of Arduino
}

void loop()
{

float Asensorval=analogRead(A0);

if(Asensorval<=700&&Asensorval>400)    //Calibrate the values as per requirement, View the Asensorval using Serial Monitor Feature of Arduino
{
ServoDemo.write(0); delay(800);        //Change Delay values to vary the speed of Wiper
ServoDemo.write(200); delay(800);}

else if(Asensorval<=400){
ServoDemo.write(0); delay(400);
ServoDemo.write(180); delay(400);}

else if(Asensorval>700)
{
ServoDemo.write(0);
}
delay(20);  

}
