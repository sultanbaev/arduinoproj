// постоянные
const int button = 7;
// пин для кнопки
const int gerkon = 9;
// пин для геркона
const int sirena = 13;
// пин упр-ния сиреной
const int led = 11;
// пин индикатора

// переменные
int buttonState = 0;
// состояние кнопки
int gerkonState = 0; // состояние геркона
int N = 0; // счетчик кнопки отключения охраны

void setup() { // управление сиреной и индикатором — выход
  pinMode(sirena, OUTPUT);
  pinMode(led, OUTPUT); // кнопка и геркон — входы
  pinMode(gerkon, INPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(led, HIGH);
  while (buttonState == 0) { // цикл ожидания, пока не нажмем кнопку
    buttonState = digitalRead(button); // для перехода в режим охраны
    Serial.println("Ждем нажатия кнопки");
  } digitalWrite(led, LOW);
  buttonState = 0; // обнуляем значение кнопки
  while (gerkonState == 0) { // цикл, пока не закроем дверь
    gerkonState = digitalRead(gerkon);
  } delay (500); // :-)
  digitalWrite(sirena, HIGH); // Код
  delay (100); // индикации
  digitalWrite(sirena, LOW); // включения
  delay (70); // режима
  digitalWrite(sirena, HIGH); // охраны
  delay (100); // оповещение
  digitalWrite(sirena, LOW); // звуковое
  while (gerkonState == 1) { // ждем открытия двери
    gerkonState = digitalRead(gerkon);
  }
  for (int i = 0; i <= 5; i++) { // 7,5 секунды на нажатие
    buttonState = digitalRead(button); // секретной кнопки
    if (buttonState == HIGH) { // отслеживаем свой — чужой
      N = N + 1;
    }
    delay(1500); // секретная фича :-)))
  }
  if (N > 0) { // самое главное
    digitalWrite(sirena, LOW); // не включаем сирену
  }
  else {
    digitalWrite(sirena, HIGH); // или включаем сирену
  } digitalWrite(led, HIGH); // включаем индикатор
  N = 0;
  buttonState = 0;
  delay(15000); // напоминание «чайникам», которым нравится
  digitalWrite(led, LOW); // давить на кнопки без перерыва
  delay (1000);
}

