int pezoel = 13;
int ledpin = 11;
int gerkon = 9;
int buttonpin = 7; 

int count = 0;
//int cancelcall = 0;



// -----------------------------------------------------------------------------------
void setup()
  {
    pinMode(pezoel, OUTPUT);
    
    pinMode(gerkon, INPUT);
    digitalWrite(gerkon, HIGH);
    
    pinMode(ledpin, OUTPUT);

    pinMode(buttonpin, INPUT);

    Serial.begin(9600);
  }
// -----------------------------------------------------------------------------------



// -----------------------------------------------------------------------------------
void loop()
  {
    int gerkonstat = digitalRead(gerkon); // читаем геркон
    //int buttonstate = digitalRead(buttonpin); // читаем кнопку

      if (digitalRead(gerkon) == LOW) // если геркон с магнитом
        {
          count = 0;
          //------------------------------Serial.println("ОК"); // то все ок
        }
    
      if (digitalRead(gerkon) == HIGH) // если геркон один
        {
          //--------------------------------Serial.println("Дверь открыта");
          //delay(5000);
          digitalWrite(pezoel, HIGH); // пищим и считаем сколько раз
          delay(20);
          digitalWrite(pezoel, LOW);
          delay(1000);
          //-----------------------------------Serial.println("Сигналим");
          count = count + 1;

            //int buttonstate = digitalRead(buttonpin); // читаем кнопку
            //if (buttonstate == HIGH) // если кнопка нажата
            //{
              //cancelcall = 1; // отменяем звонок
            //}
        }

      //if ((count == 5) && (cancelcall == 0)) // если пропищали 7 раз и кнопка не была нажата, то звоним на телефон
      if (count == 7)
        {
          //-------------------------------------Serial.println("Звоним");
          digitalWrite(ledpin, HIGH);
          delay(5000);
          digitalWrite(ledpin, LOW);
          count = 0;  // и сбрасываем счетчик
        }
    
    //Serial.println(gerkonstat);
    //----------------------------------------------Serial.println(count);
    //delay(1000);
    
    //digitalWrite(pezoel, HIGH);
    //delay(50);
    //digitalWrite(pezoel, LOW);
    //delay(1000);
  }
// -----------------------------------------------------------------------------------
