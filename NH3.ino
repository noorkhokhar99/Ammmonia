/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

float volt1;
float volt;
unsigned int lettura = 0; //actual read value
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  volt= analogRead(A0);
  volt1= (volt*5)/1023;
  float volt2 = volt1*(500/2);
  lettura = analogRead(A1);
   //lettura = map(lettura,0,1023,350,10000);
  lettura = map(lettura,250,1023,0,50);
  // read the input on analog pin 0:
  //int sensorValue = analogRead(A0);
  // print out the value you read:
  
 //  Serial.println(volt2);
 //  Serial.println(volt);
   Serial.print(lettura);
   Serial.print(" PPM");
   //Serial.print(lettura);
   Serial.print("\n");
  delay(2000);        // delay in between reads for stability
}
