/*************************************************************

  This example shows how to send values to the Blynk App,
  when there is a widget, attached to the Virtual Pin and it
  is set to some frequency

  Project setup in the app:
    Value Display widget attached to V5. Set any reading
    frequency (i.e. 1 second)
 *************************************************************/

#define BLYNK_AUTH_TOKEN "27HrhEvgLcCP3phxmvoHPhBFo6v28wMP"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "BanTon-Aoy";
char pass[] = "0890397425";

// Use Virtual pin 5 for uptime display
#define blynk_soil_pin V5

// This function tells Arduino what to do if there is a Widget
// which is requesting data for Virtual Pin (5)
BLYNK_READ(blynk_soil_pin)
{

  Blynk.virtualWrite(blynk_soil_pin, millis() / 1000);
}

void setup()
{

  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

}

void loop()
{
  Blynk.run();
}
