// постоянные
const int button = 7; // пин для кнопки
const int gerkon = 9; // пин для геркона
const int sirena = 13; // пин упр-ния сиреной
const int led = 11; // пин индикатора

// переменные
int buttonState = 0; // состояние кнопки
int gerkonState = 0; // состояние геркона
int N = 0; // счетчик кнопки отключения охраны
int s = 0; // счетчик сирены
int value = LOW; // состояние светодиода
long previousMillis = 0; // переменная подсчета времени без delay
int doorDelay = 0; // переменная задержки автовключения охраны

// изменяемые переменные
int timeDelay = 50; // время задержки (t/10=секунды) на снятие с охраны
int autoSec = 15; // время (сек) автоматической постановки на охрану после закрывания двери

void setup()
{
  // управление сиреной и индикатором — выход
  pinMode(sirena, OUTPUT);
  pinMode(led, OUTPUT);
  
  // кнопка и геркон — входы
  pinMode(gerkon, INPUT);
  pinMode(button, INPUT);
}

void loop()
{
  digitalWrite(led, HIGH);
  while (buttonState == 0)
  {
    // цикл ожидания, пока не нажмем кнопку
    buttonState = digitalRead(button);
    
    // для перехода в режим охраны
    if (s == 1)
    {
      if (millis() - previousMillis > 500)
      {
        
        // прерывистая работа сирены
        previousMillis = millis();
        digitalWrite(sirena, LOW);
        delay(200);
        digitalWrite(sirena, HIGH);
      }
    }

    if (digitalRead(gerkon) == 1)
    {
      
      // автоматическая постановка на охрану после закрывания двери
      if (millis() - previousMillis > 1000)
      {
        previousMillis = millis();
        doorDelay++;
      }
      if (doorDelay == autoSec)
      {
        buttonState = 1;
      }
    }
    else
    {
      doorDelay = 0;
    }
  }

  digitalWrite(led, LOW);
  buttonState = 0; // обнуляем значение кнопки
  s = 0;
  previousMillis = 0;
  //digitalWrite(sirena, LOW); // отключение сирены кнопкой
  while (gerkonState == 0)
  {
    // цикл, пока не закроем дверь
    gerkonState = digitalRead(gerkon);
  }

  delay (500); // :-)
  digitalWrite(sirena, HIGH); // Код
  delay (70); // индикации
  digitalWrite(sirena, LOW); // включения
  delay (70); // режима
  digitalWrite(sirena, HIGH); // охраны
  delay (70); // оповещение
  digitalWrite(sirena, LOW); // звуковое
  while (gerkonState == 1)
  {
    // ждем открытия двери
    gerkonState = digitalRead(gerkon);
  }

  for (int i=0; i <= 5; i++)
  {
    // самое главное
    digitalWrite(sirena, LOW); // не включаем сирену
  } else
  {
    s = 1;
    digitalWrite(sirena, HIGH); // включаем сирену
    delay(10000); // непрерывно на 10 секунд
  }
  digitalWrite(led, HIGH); // включаем индикатор
  N = 0;
  buttonState = 0;
  N = 0;
  doorDelay = 0;
  delay(2000); // напоминание «чайникам», которым нравится давить на кнопки без перерыва
  delay (1000);
  digitalWrite(led, LOW);
}

