// Avoid use pin 0,1,3,6,7,8,9,10,11,12

#define soil_pin_1 13
//#define soil_pin_2 4
//#define soil_pin_3 5
#define water_pin_1 14
//#define water_pin_2 14

/*
#define BLYNK_AUTH_TOKEN "27HrhEvgLcCP3phxmvoHPhBFo6v28wMP"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "BanTon-Aoy";
char pass[] = "0890397425";

#define blynk_soil_pin V5
#define blynk_water_pin V4
*/

void setup() {
  
  Serial.begin(115200);
  //Blynk.begin(auth, ssid, pass);
  pinMode(soil_pin_1, INPUT);
  pinMode(water_pin_1, OUTPUT);

}


void loop() {

  //Blynk.run();
  
  
  float th = 3500;
  
  delay(10000);
  float soil_moist_val = analogRead(soil_pin_1);
  //Blynk.virtualWrite(blynk_soil_pin, soil_moist_val);
  
  if (soil_moist_val > th){
    
    digitalWrite(water_pin_1, HIGH);
    Serial.println("Water Pump ON");
    Serial.print("Moisture Value = ");
    Serial.println(soil_moist_val);
    //Blynk.virtualWrite(blynk_water_pin, water_pin_1);
    delay(1000);
    
    digitalWrite(water_pin_1, LOW);
    delay(3000);
    
  }

 
  else if (soil_moist_val <= th){
  
    digitalWrite(water_pin_1, LOW);
    Serial.println("Water Pump OFF");
    Serial.print("Moisture Value = ");
    Serial.println(soil_moist_val);
    //Blynk.virtualWrite(blynk_water_pin, water_pin_1);

  }

  

}
