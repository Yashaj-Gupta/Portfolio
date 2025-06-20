int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup() 
{
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  if (Serial.available()) 
  {
    String input = Serial.readStringUntil('\n'); 

    int r, g, b;

    sscanf(input.c_str(), "%d,%d,%d", &r, &g, &b);

    analogWrite(redPin, r);
    analogWrite(greenPin, g);
    analogWrite(bluePin, b);
    
  }
}
