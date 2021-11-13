// Avoid use pin 0,1,3,6,7,8,9,10,11,12

#define soil_pin_1 13
//#define soil_pin_2 4
//#define soil_pin_3 5
#define water_pin_1 14
//#define water_pin_2 14


void setup() {

  Serial.begin(9600);
  pinMode(soil_pin_1, INPUT);
  pinMode(water_pin_1, OUTPUT);

}

void loop() {

  float th = 3500;
  float soil_moist_val = analogRead(soil_pin_1);
  delay(10000);
  
  if (soil_moist_val > th){
    
    digitalWrite(water_pin_1, HIGH);
    Serial.println("Water Pump ON");
    delay(750);
    digitalWrite(water_pin_1, LOW);
    delay(3000);
  }

 
  else if (soil_moist_val <= th){
  
    digitalWrite(water_pin_1, LOW);
    Serial.println("Water Pump OFF");

  }

  Serial.print("Moisture Value = ");
  Serial.println(soil_moist_val);

}
