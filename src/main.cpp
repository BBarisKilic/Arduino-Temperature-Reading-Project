#include <Arduino.h>
#include <SoftwareSerial.h>
//Add this external library to be able to use DHT11 or DHT22 sensor.
//In Arduino IDE: Sketch -> Include Library -> Manage Libraries
//And search "DHT" then install library which provided by "Adafruit".
#include <DHT.h>

#define DHTPIN 4
//We used DHT11 sensor but if you use something else, just change it.
#define DHTTYPE DHT11

SoftwareSerial BTserial(2, 3);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  BTserial.begin(9600); 
  dht.begin();
}

void loop() {
  
  int temperature = dht.readTemperature();
  int humidity = dht.readHumidity();
 
  //This line adds 'T' char to beginning and then sends temperature value.
  //So app will be able to understand that incoming data is temperature.
  //Important: Do not use 'write' or 'print'. Only 'println'.
  BTserial.println("T" + String(temperature));

  //We recommend you to not change this value.
  delay(200);
  
  //This line adds 'H' char to beginning and then sends temperature value.
  //So app will able to understand that incoming data is humidity.
  //Important: Do not use 'write' or 'print'. Only 'println'.
  BTserial.println("H" + String(humidity));

  //Set minimum 200 or more.
  delay(1800);
}