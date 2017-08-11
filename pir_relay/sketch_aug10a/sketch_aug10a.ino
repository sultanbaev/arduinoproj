//Время калибровки датчика (10-60 сек. по даташиту)
int calibrationTime = 1;       

//Время, в которое был принят сигнал отсутствия движения(LOW)
long unsigned int lowIn;        

//Пауза, после которой движение считается оконченным
long unsigned int pause = 2000; 

//Флаг. false = значит движение уже обнаружено, true - уже известно, что движения нет
boolean lockLow = true;
//Флаг. Сигнализирует о необходимости запомнить время начала отсутствия движения
boolean takeLowTime; 

int pirPin = 2;    //вывод подключения PIR датчика
int ledPin = 13;   //вывод сигнального диода
int relayPin = 4;  //реле пин
int ldr = A0;       //и фоторезистора

void setup()
{
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(relayPin, OUTPUT);

  //!ВНИМАНИЕ! При использовании n-p-n реле необходимо в след. строчке поменять HIGH на LOW
  digitalWrite(relayPin, HIGH);
  delay(4000);
  digitalWrite(pirPin, LOW);

  //дадим датчику время на калибровку
  for(int i = 0; i < calibrationTime; i++)
  {
    //Во время калибровки будет мигать сигнальный диод
    i % 2 ? digitalWrite(ledPin, HIGH) : digitalWrite(ledPin, LOW);
    delay(1000);
  }
  //По окончанию калибровки зажжем сигнальный диод 
  //digitalWrite(ledPin, HIGH);
  delay(50);
}

void loop()
{ //-------------------------------------------------------------------------

//
if (analogRead(ldr) > 800) {

  //Если обнаружено движение
  if(digitalRead(pirPin) == HIGH)
  {
    //Если до этого момента еще не включили реле
    if(lockLow)
    {
      lockLow = false;      
      //Включаем реле.
      //!ВНИМАНИЕ! При использовании n-p-n реле необходимо в след. строчке поменять LOW на HIGH
      digitalWrite(relayPin, LOW);
      delay(50);
    }        
    takeLowTime = true;
  }

  //Ели движения нет
  if(digitalRead(pirPin) == LOW)
  {      
    //Если время окончания движения еще не записано
    if(takeLowTime)
    {
      lowIn = millis();          //Сохраним время окончания движения
      takeLowTime = false;       //Изменим значения флага, чтобы больше не брать время, пока не будет нового движения
    }
    //Если время без движение превышает паузу => движение окончено
    if(!lockLow && millis() - lowIn > pause)
    { 
      //Изменяем значение флага, чтобы эта часть кода исполнилась лишь раз, до нового движения
      lockLow = true;                
      digitalWrite(relayPin, HIGH);
      delay(50);
    }
  }

}

else {lockLow = true;                
      digitalWrite(relayPin, HIGH);
      delay(50);}
//




} // --------------------------------------------------------------------
