#include <WiFi.h>

const char* my_ssid = "BanTon-Aoy";
const char* my_pwd = "0890397425";


void setup() {
  Serial.begin(9600);
  WiFi.begin(my_ssid, my_pwd);
  Serial.println("Connecting to " + ((String)my_ssid));
  while(WiFi.status() != WL_CONNECTED){
    Serial.print("connecting ");
    Serial.println(".....");
    delay(500);
  }
  Serial.println();
  Serial.println("Connected to " + ((String)my_ssid) + " Successfully!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

void loop() {

}
