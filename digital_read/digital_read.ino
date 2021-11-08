void setup() {
  Serial.begin(9600);
  pinMode(14, INPUT);
  

}

void loop() {
  int val = digitalRead(14);
  Serial.print("SW=");
  Serial.println(val);
  delay(100);
 
  

} 
