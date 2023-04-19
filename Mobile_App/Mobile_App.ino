#define BLYNK_TEMPLATE_ID "TMPL63g7Od8A"
#define BLYNK_DEVICE_NAME "Water Level Monitoring System"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// sensor 1
const int trigPin1 = D1;
const int echoPin1= D2;
const int relay1 = D7;
long duration1;
int distance1;
int safetyDistance1;
// sensor 2
const int trigPin2 = D3;
const int echoPin2= D4;
const int relay2 = D8;
long duration2;
int distance2;
int safetyDistance2;
// sensor 3
const int trigPin3 = D5;
const int echoPin3= D6;
const int relay3 = D0;
long duration3;
int distance3;
int safetyDistance3;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "WBiTmA2wjrfOQzr_1RFdvRjnFcH-I5iL";
char ssid[] = "TP_LINK"; // Your WiFi credentials.
char pass[] = "parth1892"; // Set password to "" for open networks.
BlynkTimer timer;
void setup()
{
  // Debug console
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT);
  pinMode(relay1, OUTPUT);
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT);
  pinMode(relay2, OUTPUT);// Sets the echoPin as an Input
  pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin3, INPUT);
  pinMode(relay3, OUTPUT);// Sets the echoPin as an Input
}

void loop()
{
  {
     Blynk.run();
     timer.run(); 
  }
  digitalWrite(trigPin1, LOW);
delayMicroseconds(2);

digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);

digitalWrite(trigPin1,LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echoPin1,HIGH);
// Calculating the distance
distance1= duration1*0.034/2;
Serial.print("Ultra 1: ");
delay (100);
Serial.println(distance1);
delay (100);
Blynk.virtualWrite(V0, distance1);
delay(50);
safetyDistance1 = distance1;
if((distance1>=4))
  {
    digitalWrite(relay1, LOW);
    delay(100);
  }
   else if(distance1<=3)
 {
     digitalWrite(relay1, HIGH);
     delay(100);  
  }


// Ultra 2
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);

digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);

digitalWrite(trigPin2,LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration2 = pulseIn(echoPin2,HIGH);
// Calculating the distance
distance2= duration2*0.034/2;
Serial.print("Ultra 2: ");
delay (100);
Serial.println(distance2);
delay (100);
Blynk.virtualWrite(V1 , distance2);
delay(50);
safetyDistance2 = distance2;
if((distance2>=4))
  {
    digitalWrite(relay2, LOW);
    delay(100);
}
   else if(distance2<=3)
 {
     digitalWrite(relay2, HIGH);
     delay(100);
   }
   

// Ultra 3
digitalWrite(trigPin3, LOW);
delayMicroseconds(2);

digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);

digitalWrite(trigPin3,LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration2 = pulseIn(echoPin3,HIGH);
// Calculating the distance
distance3= duration2*0.034/2;
Serial.print("Ultra 3: ");
delay (100);
Serial.println(distance3);
delay (100);
Blynk.virtualWrite(V4 , distance3);
delay(50);
safetyDistance3 = distance3;
if((distance3>=4))
  {
    digitalWrite(relay3, LOW);
    delay(100);
}
   else if(distance3<=3)
 {
     digitalWrite(relay3, HIGH);
     delay(100);
   }

}
