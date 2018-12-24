/*Code for the features described in the readme file. 
Hardware needed are GSM SIM900A, Neo 6m GPS module, Alcohol sensor(MQ-3), DHT-11, SW420 Impact Sensor. 
In this example, all components are connected to a single Arduino*/

#include <SoftwareSerial.h>
#include <dht.h>                
#include <TinyGPS++.h>         //Packages for DHT11 and Neo6m GPS module 

int vibr_Pin =7;     // Connect output of Impact Sensor here  
int valor_limit =600;
float valor_alcohol;


SoftwareSerial mySerial(9, 10);  // initializing pwm pins for serial communication between Arduino and GSM Module. Put tx of GSM module to pin 9 ,rx of GSM module to pin 10 of arduino
SoftwareSerial ss(5, 3);         // initializing pwm pins for serial communication between Arduino and GPS Module
TinyGPSPlus gps;
dht DHT;

void setup() {
  mySerial.begin(9600);   // Baud rate of GSM Module  
  delay(100);
  ss.begin(9600);  // Baud rate for GPS
  delay(100);
  pinMode(12,INPUT);  // Connect a Panic button/pushbutton
  pinMode(13,OUTPUT); // Led Indicator (optional)
  pinMode(8,OUTPUT);  //buzzer attached which is activated when Alcohol Level becomes more than threshold
  Serial.println("AT+CNMI=2,2,0,0,0"); // For GSM Module to receive messages
  delay(1000);  
}

void loop() {
    while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){    
       
int pushbutton=digitalRead(12);
digitalWrite(8,LOW);

if(pushbutton==HIGH){                // Checks if panic button is pressed or not
digitalWrite(13,LOW);                
SendMessage1();
delay(15000);
}

else if(pushbutton==LOW)
{digitalWrite(13,HIGH);

     if (mySerial.available()>0){
     char text=mySerial.read();
     if (text=='!'){digitalWrite(13,LOW);SendMessage3();delay(15000);}}   // For Cabin Monitoring, Define a message to be sent to the GSM in car, for eg. "Hello!" 

     int val;
     val=digitalRead(vibr_Pin);      
     if(val==1)   
     {     
      digitalWrite(13,LOW);
      SendMessage2();
      delay(15000);
     } 
        
     valor_alcohol=analogRead(A5);
     if(valor_alcohol > valor_limit){
     digitalWrite(8,HIGH);
     digitalWrite(13,LOW); 
     SendMessage4();delay(15000);
     }          
        
     }


}
    }
}

 void SendMessage1()                                 // Panic Button Message Loop
{
 
  mySerial.println("AT+CMGF=1");  
  delay(1000);  
  mySerial.println("AT+CMGS=\"+91**********\"\r");     // insert the number where the alert should be sent  
  delay(1000);
  mySerial.println("Passenger Safety Alert , Panic Button is Pressed");
  mySerial.println("Latitude and Longitude : ");delay(50);Serial.print(gps.location.lat(), 6);
  delay(100);Serial.print(",");delay(50);
  mySerial.println(gps.location.lng(), 6);
  delay(100);
  mySerial.println("https://www.google.co.in/maps?source=tldsi&hl=en"); 
  mySerial.println((char)26);
  delay(1000);
}


 void SendMessage2()                                 // Accident Alert Loop
{
 
  mySerial.println("AT+CMGF=1");  
  delay(1000);  
  mySerial.println("AT+CMGS=\"+91**********\"\r"); 
  delay(1000);
  mySerial.println("Car Accident Detected");
  delay(100);
  mySerial.println((char)26);
  delay(1000);
}

 void SendMessage3()                                   // Cabin Environment Reading and Sending  
{
 
  mySerial.println("AT+CMGF=1");  
  delay(1000);  
  mySerial.println("AT+CMGS=\"+91**********\"\r"); 
  delay(1000);
  DHT.read11(A0);
  delay(1000);
  mySerial.println("Hi ");delay(50);
  mySerial.println("Temperature : ");delay(50);Serial.print(DHT.temperature);delay(50);Serial.println(" Celcius");delay(50);
  mySerial.println("Humidity : ");delay(50);Serial.print(DHT.humidity);delay(50);Serial.println(" %");delay(50);
  mySerial.println("Alcohol level in air :");delay(50);Serial.println(analogRead(A5));delay(50);
  mySerial.println((char)26);
  delay(1000);
}

 void SendMessage4()                                   // Drunk Driver Alert    
{
 
  mySerial.println("AT+CMGF=1");  
  delay(1000);  
  mySerial.println("AT+CMGS=\"+91**********\"\r"); 
  delay(1000);
  mySerial.println("Drunk Driver Alert");
  delay(100);
  mySerial.println((char)26);
  delay(1000);
}
