int ledPin = 13;
int buttonOnPin = 12;
int shockKy002Sensor = 11;

//int shockKy002SensorValue;

boolean lastButton = false; // предыдущее состояние кнопки
boolean currentButton = false; // текущее состояние кнопки
boolean ledOn = false; // состояние светодиода

void setup() {
  //Serial.begin(9600);
  pinMode (ledPin, OUTPUT);  
  pinMode (buttonOnPin, INPUT);
  pinMode (shockKy002Sensor, INPUT);
}

void loop() {
  currentButton = debounce (lastButton); // получаем состояние кнопки без дребезга
  if (lastButton == false && currentButton == true) { // если кнопка была нажата дольше 5 мсек,
    ledOn = !ledOn; // то меняем состояние светодиода
  }
  lastButton = currentButton; // обнуляем состояние нажатия кнопки
  digitalWrite(ledPin, ledOn); // зажигаем/гасим светодиод

//*/
if (digitalRead(ledPin) == HIGH) {
    int shockKy002SensorValue = digitalRead(shockKy002Sensor); // чтение состояния датчика
      if (shockKy002SensorValue == LOW) // когда датчик детектирует удар, светодиод загорается 
      {
        //digitalWrite (ledPin, LOW);
        //Serial.println(shockKy002SensorValue);
      }
      else
      {
        //digitalWrite (ledPin, HIGH);
      }
    }
//*/

}

// Процедура определения нажатия кнопки без дребезга:
boolean debounce(boolean last) { 
  boolean current = digitalRead(buttonOnPin); // считываем текущее состояние кнопки
  if (last != current) { // если состояние изменилось
    delay(5); // делаем задержку на 5 мсек, пока уляжется дребезг
    current = digitalRead(buttonOnPin); // и считываем снова
  }
  return current; // возвращаем текущее состояние кнопки
}
