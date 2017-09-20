int baudRate = 9600;  //This is how many bps we're communicating with the computer at (default 9600)
int samplePeriod = 1000;  //This is how often we take a sample in msec (default 1000)
float gain0 = 1; //This is the gain that we can use to calibrate the analog input measurements (default 1)
float offset0 = 0; //This is the offset that we can use to calibrate the analog input measurements (default 0)
float gain1 = 1; //This is the gain that we can use to calibrate the analog input measurements (default 1)
float offset1 = 0; //This is the offset that we can use to calibrate the analog input measurements (default 0)

void setup() {  //This is where we set up pin modes and start serial communication
  Serial.begin(baudRate); //Start serial communication
  pinMode(A0, INPUT); //Set the first analog input pin as an input
  pinMode(A1, INPUT); //Set the second analog input pin as an input
  pinMode(13, OUTPUT);  //Set the LED pin as an output
  digitalWrite(13, LOW);  //Set the LED pin to off
}

void loop() { //This is the part that keeps running as long as power is supplied
  int reading0 = 0;  //Start a carrier variable for the reading
  int reading1 = 0; //Start a carrier variable for the reading
  reading0 = analogRead(A0);  //Read the analog pin value (0-1023) into the carrier variable
  reading1 = analogRead(A1);  //Read the analog pin value (0-1023) into the carrier variable
  if(reading0 < reading1){  //If the first analog channel is less than the second, then
    digitalWrite(13, HIGH); //Turn on the LED
  }
  if(reading0 >= reading1){ //If the first analog channel is greater than or equal to the second, then
    digitalWrite(13, LOW);  //Turn off the LED
  }
  Serial.print(gain0 * reading0 + offset0); //Send the first adjusted value to the computer
  Serial.print(",");  //Send a comma to separate the values to the computer
  Serial.println(gain1 * reading1 + offset1); //Send the second adjusted value to the computer
  delay(samplePeriod)  //Delay until the sample period has gone by
}
