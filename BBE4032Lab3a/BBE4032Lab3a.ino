int baudRate = 9600;  //This is how many bps we're communicating with the computer at (default 9600)
int samplePeriod = 1000;  //This is how often we take a sample in msec (default 1000)
float gain = 1; //This is the gain that we can use to calibrate the analog input measurements (default 1)
float offset = 0; //This is the offset that we can use to calibrate the analog input measurements (default 0)

void setup() {  //This is where we set up pin modes and start serial communication
  Serial.begin(baudRate); //Start serial communication
  pinMode(A0, INPUT); //Set the first analog input pin as an input
}

void loop() { //This is the part that keeps running as long as power is supplied
  int reading = 0;  //Start a carrier variable for the reading
  reading = analogRead(A0); //Read the analog pin value (0-1023) into the carrier variable
  Serial.println(gain * reading + offset);  //Send the adjusted value to the computer and print a line return
  delay(samplePeriod);  //Delay until the sample period has gone by
}
