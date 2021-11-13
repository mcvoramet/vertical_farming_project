
#include <FastLED.h>

#define NUM_LEDS 60 //จำนวนเม็ด LED บนแถบ LED

#define DATA_PIN 17 // สำหรับ Arduino ใช้ขา digital ปกติ สำหรับ ESP8266 ให้ใช้เลขขา GPIO (ไม่ใช่ขา digital) 

CRGB leds[NUM_LEDS];

void setup() {
Serial.begin(115200);
Serial.println("resetting");
LEDS.addLeds<WS2812B,DATA_PIN,RGB>(leds,NUM_LEDS);
LEDS.setBrightness(30); //ปรับความสว่าง 0-255
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }

void loop() {
static uint8_t hue = 0;
Serial.print("x");
 
// สร้างสีให้วิ่งไปทางนึง
for(int i = 0; i < NUM_LEDS; i++) {
leds[i] = CHSV(hue++, 255, 255);
FastLED.show();
fadeall();
delay(10);
}
Serial.print("x");

// และวิ่งกลับมาอีกทางนึง
for(int i = (NUM_LEDS)-1; i >= 0; i--) {
leds[i] = CHSV(hue++, 255, 255);
FastLED.show();
fadeall();
delay(10);
}
}
