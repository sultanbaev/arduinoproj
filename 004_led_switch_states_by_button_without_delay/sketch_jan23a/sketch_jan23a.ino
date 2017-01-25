int switchPin = 12; // пин кнопки
int ledPin = 13; // пин светодиода
boolean lastButton = false; // предыдущее состояние кнопки
boolean currentButton = false; // текущее состояние кнопки
boolean ledOn = false; // состояние светодиода

void setup() {  
  pinMode (switchPin, INPUT);
  pinMode (ledPin, OUTPUT);
}

void loop() {
  currentButton = debounce (lastButton); // получаем состояние кнопки без дребезга
  if (lastButton == false && currentButton == true) { // если кнопка была нажата дольше 5 мсек,
    ledOn = !ledOn; // то меняем состояние светодиода
  }
  lastButton = currentButton; // обнуляем состояние нажатия кнопки
  digitalWrite (ledPin, ledOn); // зажигаем/гасим светодиод
}

// Процедура определения нажатия кнопки без дребезга:
boolean debounce(boolean last) { 
  boolean current = digitalRead(switchPin); // считываем текущее состояние кнопки
  if (last != current) { // если состояние изменилось
    delay(5); // делаем задержку на 5 мсек, пока уляжется дребезг
    current = digitalRead(switchPin); // и считываем снова
  }
  return current; // возвращаем текущее состояние кнопки
}
