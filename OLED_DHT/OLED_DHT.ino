#include "DHT.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <ESP_Adafruit_SSD1306.h>

#define OLED_RESET 21
Adafruit_SSD1306 display(OLED_RESET);

#define DHTPIN 25
#define DHTTYPE DHT11 

float h=0.00;
float t=0.00;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  display.begin(SSD1306_SWITCHCAPVCC,0x78>>1);
  display.display();
  delay(100);
  display.clearDisplay();
}

void loop() {
  h = dht.readHumidity();
  t = dht.readTemperature();
  Serial.print(t); Serial.print("\t");
  Serial.print(h); Serial.print("\n");

  showTemp(t,h);

  delay(1000);
}

void showTemp(float temp, float hum){

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("T->");
  display.print(temp);
  display.println("C");
  display.print("H->");
  display.print(hum);
  display.println("%");
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("----------------------");
  display.println("-SMART FARM-----------");
  display.println("IP:______________");
  
  display.display();
  delay(100);
  display.clearDisplay();

}
