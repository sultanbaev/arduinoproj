// KY-020 датчик переключающий контакты при наклоне
int led = 13 ;// назначение пина для светодиода
int tiltSensorPin = 11; // назначение пина для датчика наклона
int value ;// переменная для хранения значения датчика
void setup ()
{
  pinMode (led, OUTPUT) ;// пин светодиода работает как выход
    pinMode (tiltSensorPin, INPUT) ; //пин дачика наклона работает как вход
}
void loop ()
{
  value = digitalRead (tiltSensorPin) ;// чтение значения с датчика
    if (value == HIGH) // когда с датчика появляется высокий уровень то светодиод горит
  {
    digitalWrite (led, HIGH);
  }
  else
  {
    digitalWrite (led, LOW);
  }
}
