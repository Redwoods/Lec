// DHT22
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);
// CdS (LDR)
#define CDS_INPUT 0

void setup() {
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  int cds_value, lux;
  float temp, humi;
  // Lux from CdS (LDR)
  cds_value = analogRead(CDS_INPUT);
  lux = int(luminosity(cds_value));
  // Reading temperature or humidity takes a given interval!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  humi = dht.readHumidity();
  // Read temperature as Celsius (the default)
  temp = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humi) || isnan(temp) || isnan(lux)) {
    Serial.println("Failed to read from DHT sensor or CdS!");
    return;
  }
  else {    
    Serial.print("AAnn,");
    Serial.print(temp,1);  // temperature
    Serial.print(",");
    Serial.print(humi,1);  // humidity
    Serial.print(",");
    Serial.println(lux);   // luminosity
  }  
  delay(2000);  // 2000 msec, a data per 6 min = 6 * 60 * 1000 = 360000
}

//Voltage to LuxLux
double luminosity (int RawADC0){
  double Vout=RawADC0*0.0048828125;  // 5/1024 (Vin = 5 V)
  int lux=(2500/Vout-500)/10;  
  // lux = 500 / Rldr, Vout = Ildr*Rldr = (5/(10 + Rldr))*Rldr
  return lux;
}
