const int buttonPin = 12; 
const int ledPin =  13;
int count = 0;

void setup()
{

  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);      
}

void loop()
{
  int buttonState; 
  buttonState = digitalRead(buttonPin);

if (buttonState == HIGH){
  
  if (count == 0)
  {
    digitalWrite(ledPin, HIGH); count = 1;
  }

  else
  {
    digitalWrite(ledPin, LOW); count = 0;
  }

//  if ((buttonState == HIGH) && (count == 1))
//  {
//    digitalWrite(ledPin, LOW);
//  }

}
}
