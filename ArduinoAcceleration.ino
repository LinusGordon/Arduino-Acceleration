/* 
  Tilt Switches connected to a Light Blue Bean Arduino was used to implement this code.
  The tilt switches detect a change in acceleration, changing the LED color on the Light
  Blue Bean.

  Note: the default LED color is no color. 
*/

// Pin Values
#define X_VAL 3
#define Y_VAL 4
#define Z_VAL 5

void setup() {
  
  // Pin values are set
  pinMode(X_VAL, INPUT_PULLUP);
  pinMode(Y_VAL, INPUT_PULLUP);
  pinMode(Z_VAL, INPUT_PULLUP);

}

void loop() {

   // Find RGB color values
   uint16_t r = setColorVal(X_VAL);
   uint16_t g = setColorVal(Y_VAL);
   uint16_t b = setColorVal(Z_VAL);

   // Update LED color
   // Note: if all RGB values are 0, the LED is turned off
   Bean.setLed((uint8_t)r,(uint8_t)g,(uint8_t)b);

   Bean.sleep(50);
}

// Returns the appropriate RGB value for the tilt switch's orientation
uint16_t setColorVal(uint16_t tilt_switch) { 

  int tilted = digitalRead(tilt_switch);
  
  if(tilted == HIGH) {
    return 255;
  } else {
    return 0;
  }
    
}

