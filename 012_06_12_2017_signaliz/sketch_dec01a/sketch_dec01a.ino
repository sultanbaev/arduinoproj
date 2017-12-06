int pezoel = 13;
int ledpin = 11;
int gerkon = 9;
int buttonpin = 7;

int count = 0;





// -----------------------------------------------------------------------------------
void setup()
{
  pinMode(pezoel, OUTPUT);

  pinMode(gerkon, INPUT);
  digitalWrite(gerkon, HIGH);

  pinMode(ledpin, OUTPUT);

  pinMode(buttonpin, INPUT);

  Serial.begin(9600);
}//setup
// -----------------------------------------------------------------------------------



// -----------------------------------------------------------------------------------
void loop()
{

  // ----------------------------
  while (digitalRead(gerkon) == LOW)
  {
    count = 0;
    Serial.println("ОК");
  }//while
  // ----------------------------

  // ----------------------------
  while ((digitalRead(gerkon) == HIGH) && (count < 10))
  {
    Serial.println("Дверь открыта");
    digitalWrite(pezoel, HIGH); delay(50);
    digitalWrite(pezoel, LOW); delay(20);
    digitalWrite(pezoel, HIGH); delay(50);
    digitalWrite(pezoel, LOW); delay(1000);

    Serial.println("Сигналим");
    count = count + 1;
    Serial.println(count);
  }//while
  // ----------------------------

  // ----------------------------
  alarmcall ();
  // ----------------------------

}//loop
// -----------------------------------------------------------------------------------




// -----------------------------------------------------------------------------------
void alarmcall ()
{
  // ----------------------------
  Serial.println("Звоним");
  digitalWrite(ledpin, HIGH); delay(5000);
  digitalWrite(ledpin, LOW);
  count = 0;  // и сбрасываем счетчик
  // ----------------------------  
}//alarmcall
// -----------------------------------------------------------------------------------
