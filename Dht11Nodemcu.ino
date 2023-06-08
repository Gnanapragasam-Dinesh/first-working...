 // TECHATRONIC.COM  
 // DHT11 LIBRARY  
 // https://github.com/adafruit/DHT-sensor-library  
 #include "DHT.h"  
 DHT dht2(5,DHT11);  
 void setup()  
 {  
  Serial.begin(9600); 
  dht2.begin(); 
 }  
 void loop()  
 {  
  // Wait a few seconds between measurements.
  delay(1000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  int h = dht2.readHumidity();
  // Read temperature as Celsius (the default)
  int t = dht2.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  int f = dht2.readTemperature(true);
 delay(1000);
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  int hif = dht2.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  int hic = dht2.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("C / "));
  Serial.print(f);
  Serial.print(F("F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("C "));
  Serial.print(hif);
  Serial.println(F("F"));

 } 