//KY-031 датчик удара
int led = 13 ;// встроенный в адуино светодиод
int shockSensor = 11; // пин для подключения датчика
int value; // переменная состояния датчика
void setup ()
{
  pinMode (led, OUTPUT) ; 
  pinMode (shockSensor, INPUT) ; // назначение входа для датчика
}
void loop ()
{
  value = digitalRead (shockSensor) ; // чтение состояния датчика
  if (value == HIGH) // когда датчик детектирует удар, светодиод загорается 
  {
    digitalWrite (led, LOW);
  }
  else
  {
    digitalWrite (led, HIGH);
  }
}