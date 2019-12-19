#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"
#define I2C_ADDRESS 0x3C
SSD1306AsciiAvrI2c oled;


int gas_sensor = A0; //Sensor pin
float m = -0.263; //Slope
float b = 0.42; //Y-Intercept
float R0 = 2.19; //Sensor Resistance in fresh air from previous code

void setup() {
  Serial.begin(9600); //Baud rate
  Serial.println("NH3 Sense MT");
 
}

void loop() {
  float sensor_volt; //Define variable for sensor voltage
  float RS_gas; //Define variable for sensor resistance
  float ratio; //Define variable for ratio
  float sensorValue = analogRead(gas_sensor); //Read analog values of sensor
  sensor_volt = sensorValue * (5.0 / 1023.0); //Convert analog values to voltage
  RS_gas = ((5.0 * 10.0) / sensor_volt) - 10.0; //Get value of RS in a gas
  ratio = RS_gas / R0; // Get ratio RS_gas/RS_air

  double ppm_log = (log10(ratio) - b) / m; //Get ppm value in linear scale according to the the ratio value
  double ppm = pow(10, ppm_log); //Convert ppm value to log scale
  double percentage = ppm / 10000; //Convert to percentage
  int PotSP = analogRead(A0);
  int Zero = analogRead(A0);
  int Spam = analogRead(A0);
  double ppmsp;
  double zerotrim;
  zerotrim = map(Zero, 0, 1023, 0, 2);  
  ppmsp = map(PotSP, 0, 1023, 0, 5000);
  Serial.print(ppm-zerotrim); //Load screen buffer with percentage value
  Serial.println("ppm"); //Load screen buffer with "%"
//  Serial.println(" ppm             "); //Load screen buffer with "%"
//  Serial.print("SP. ");
 // Serial.print(ppmsp);
 // Serial.print(" ppm             ");
  delay(2000);
}
