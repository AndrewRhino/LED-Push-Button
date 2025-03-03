int ledPIN = 13;

int buttonPIN = 2;

int time = 0;

void setup() {
  pinMode(ledPIN,OUTPUT);
  pinMode(buttonPIN,INPUT);
  Serial.begin(9600);
}

void loop() {
  //prints a notice that the light is about to flash
  Serial.println("Get ready...");
  //recieves the time from the function light_on()
  time = light_on();
  Serial.print("Reaction time = ");
  Serial.print(time);
  Serial.print("ms\n");             
  
  //reads whether the button is pressed (0 if it is not, 1 if it is)
  //Serial.println(digitalRead(buttonPIN));
  delay(2000);
}

int light_on() {
  
  //assigns a random number from 3000 to 6000 to num
  int num = random(3000,6000);
  //computer waits that long
  delay(num);
  digitalWrite(ledPIN, 1);
  unsigned long startTime = millis();
  while (digitalRead(buttonPIN) != 1) {
     //wait for button press
  }
  unsigned long endTime = millis();
  unsigned long buttonTime = endTime - startTime;
  digitalWrite(ledPIN, 0);
  return buttonTime;
}