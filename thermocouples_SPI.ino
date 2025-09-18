#include <src/thermocouples.h>

void setup() {
  Serial.begin(9600);
  thermocouples::init();
  Serial.println("Thermocouples MAX6675 were initialized...");
}

void loop() {
  static String receivedData="";
  if (Serial.available() > 0) {
    receivedData = Serial.readString();
    receivedData.trim();
    //Serial.println("Received data: " + receivedData);
    Serial.flush();
  }
  
  if (receivedData=="read_one_point;") {
    thermocouples::read_all_temp_once();
    for (size_t i = 0; i < THERMOCOUPLES_NUM; i++)
        {
          Serial.print(thermocouples::get_temp_celsius(i));
        } 
        delay(1000);
    receivedData = "";
  }
  
  if (receivedData=="read;") {
    thermocouples::read_all_temp();
    for (size_t i = 0; i < THERMOCOUPLES_NUM; i++)
        {
          Serial.print(thermocouples::get_temp_celsius(i));
        } 
        delay(1000);
  }
  
  if (receivedData=="stop_reading;") {
    thermocouples::stop_reading_temp();
    //Serial.println("Reading stoped");
    receivedData="";
  }
}
