// ****************************************************************** 
// Dallas Semiconductor DS18B20 Temperature Sensor Demo Program 
// COMP-10184 
// Mohawk College 
// I , Alexei Ougriniouk , 000776331 , certify this is my work 
 
// library for Arduino framework  
#include <Arduino.h> 
// 1-Wire sensor communication libary 
#include <OneWire.h> 
// DS18B20 sensor library 
#include <DallasTemperature.h> 
 
// Pin that the  DS18B20 is connected to 
const int oneWireBus = D3;      
 
// Setup a oneWire instance to communicate with any OneWire devices 
OneWire oneWire(oneWireBus); 
 
// Pass our oneWire reference to Dallas Temperature sensor  
DallasTemperature DS18B20(&oneWire); 

DeviceAddress Thermometer;
int deviceCount = 0;

 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // Start the DS18B20 sensor 
  DS18B20.begin(); 
  uint8_t address[8];
  if(DS18B20.getAddress(address, 0)){
    Serial.print("Address fetched:");
  }else{
    Serial.println("No Sensor Found");
    return;
    exit(0);
    
  }
 
  for(int i = 0; i<8; i++){
    Serial.printf("%02X ",address[i]);
  }
} 
 
void loop() { 
  float fTemp; 
 
  // ask DS18B20 for the current temperature 
  DS18B20.requestTemperatures(); 
 
  // fetch the temperature.  We only have 1 sensor, so the index is 0. 
  fTemp = DS18B20.getTempCByIndex(0); 
 
  // print the temp to the USB serial monitor 
 // Serial.println("Current temperature is: " + String(fTemp) + " deg. Celsius"); 
  //DS18B20.getAddress(Thermometer);

if(35 < fTemp ){
      Serial.println("Current temperature is: " + String(fTemp)  + " C or WAY TOO HOT !!"); 
  }
    else if(30 <= fTemp){
      Serial.println("Current temperature is: " +String(fTemp)  + " C or  hot!!"); 
  }
  else if(25 <= fTemp ){
      Serial.println("Current temperature is: " + String(fTemp)  + " C or  warm!!"); 
  }
else if(15 <= fTemp){
      Serial.println("Current temperature is: " + String(fTemp)  + " C or  Perfect!!"); 
  }
   else if(10 <= fTemp ){
      Serial.println("Current temperature is: " +  String(fTemp)  + " C or  cool!!"); 
  }
 
  else{
      Serial.println("Current temperature is: " +  String(fTemp)  + " C or cold!!"); 
  }
 
  // wait 5 seconds (500 ms) 
  delay(5000); 
} 
 
  
