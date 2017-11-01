/*
  Single random signals

  Simulation of random signal
*/

float sig1=0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

  sig1 = random(0,100);
  
  Serial.print("AA00, Current signal: ");
  Serial.println(sig1);
  delay(100);        // Sampling rate = 10 Hz
}

float f_map(long x, long in_min, long in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


