#include <DHT.h>
#include <Grove_Temperature_And_Humidity_Sensor.h>
#include <U8x8lib.h>

DHT dht(3, DHT11);
U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

void setup() {
pinMode(4, OUTPUT);
u8x8.begin();
u8x8.setFlipMode(1);
u8x8.clear();
dht.begin();
}

void loop() {
  //declare variables for parsing sensor data
  float t = dht.readTemperature();
  float h = dht.readHumidity();
u8x8.setFont(u8x8_font_chroma48medium8_r);
u8x8.setCursor(0, 0);
 float fahrenheit = (t * 9/5) + 32; //convert sensor temp to Fahrenheit
u8x8.println("Temp: ");
u8x8.println(fahrenheit);
u8x8.println("Humidity: ");
u8x8.print(h);
u8x8.print("%");
if(h > 70){ //if loop to check for humidity and set off buzzer and LED
  tone(5, 750, 1000);
  digitalWrite(4, HIGH);
}
digitalWrite(4, LOW);
}
