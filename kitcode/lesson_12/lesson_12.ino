/*
 * Набор для экспериментов MaxKit 01
 * Код программы для опыта №12: sketch 12
 *
 * Крутись мотор
 *
 * Написано для сайта "Полный комплект" http://maxkit.ru
 *
 *
 * Помощь сообщества Arduino.
 * Посетите сайт http://www.arduino.cc
 *
 *
 * КРУТИСЬ МОТОР
 *
 * Использование транзистора для управления скоростью мотора.
 * Мы также покажем вам, как вводить данные через последовательный порт
 * (см функцию serialSpeed() ниже).
 *
 * Двигатели одна из многочисленных вещей из нашей повседневной жизни,
 * и Arduino может ими управлять. Мы будем использовать Широтно
 * Импульсную Модуляцию (PWM) для управления скоростью двигателя.
 *
 * Порты Arduino способны выдержать работу нескольких светодиодов
 * (до 40 мА), но они не достаточно мощны, чтобы справиться с нагрузкой
 * от двигателя и других прожорливых потребителей энергии. Двигатель
 * идущий в наборе потребляет приблизительно от 50 до 100 mA, а это
 * значительно больше чем может дать Arduino. Поэтому мы будем
 * использовать транзистор, который выполнит главную работу.
 * Транзистор будет выполнять роль "твердотельного выключателя", мы
 * "дадим" ему ток маленькой величины, а будет коммутировать, гораздо
 * больший ток. Транзистор 2N2222 может коммутировать ток до 200 мА.
 *
 * Вы можете управлять транзистором с помощью функции digitalWrite()
 * ("включать" и "выключать"), а с помощью функцию analogWrite()
 * изменять скорость вращения двигателя, для этого Arduino использует
 * Широтно Импульсную Модуляцию (PWM), подавая импульсы напряжения
 * изменяя их ширину от 0% до 100%.
 *
 * Имейте в виду, для уменьшения скорости, вы уменьшаете ее с помощью
 * ШИМ (делая паузы "СТОП" длиннее). Если в начале, длительность паузы
 * будет 50% и более, двигатель, просто не сможет раскрутиться,
 * поэтому при старте необходимо немного добавить скорости.   
 *
 * Подсоединяем оборудование:
 *
 * Транзистор:
 * 
 * У транзистора имеются три вывода. Если повернуть его скошенной
 * стороной (с надписями) к себе, а выводами вниз, то назначения
 * выводов будут следующими (слева на пр.): КОЛЛЕКТОР, БАЗА, ЭМИТЕР.
 *   
 * Подсоедините минусовой вывод мотора к КОЛЛЕКТОРУ транзистора.
 * Подсоедините БАЗУ через резистор 330 Ом к цифровому порту 9.   
 * Подсоедините ЭМИТЕР к GND (минусовой шине).
 *
 * Мотор:
 *
 * Вы уже должны были подсоединить минусовой вывод мотора к
 * КОЛЛЕКТОРУ транзистора.
 *
 * В данном опыте не имеет особого значения куда плюс, а куда минус,
 * если их перепутать двигатель просто будет крутиться в обратном
 * направлении, это будет иметь значение если двигатель установлен
 * скажем, в машинке, и вместо того, чтобы ехать вперед, она
 * поедет назад.
 *  
 * Оставшийся вывод мотора подсоедините к +5 Вольт.
 *
 * Полупроводниковый диод:
 *
 * Полупроводниковый диод пропускает электрический ток только в
 * одном направлении и блокирует его прохождение в другом.
 *
 * Когда двигатель вращается, и резко отключается, магнитное поле
 * внутри него падает, в результате создается всплеск напряжения.
 * Это может привести к повреждению транзистора. Чтобы этого не
 * случилось, мы  и будем использовать диод, который не пропустит
 * этот всплеск через себя.
 *
 * На импортных диодах, почти всегда, КАТОД, отмечен полоской -
 * кольцом, расположенным, как раз у этого вывода.
 *
 * Подключите один вывод диода (КАТОД) к +5 Вольт, а другой
 * вывод (АНОД) к минусовому контакту на двигателе.
 *
 *
 *
 *
 * Этот sketch был написан SparkFun Electronics,
 * Переведен специально для сайта http://maxkit.ru
 * 01 февраля 2015г.
 *
*/

// Будем управлять двигателем используя цифровой порт 9 (pin 9).
// Это должен быть любой ШИМ порт Arduino

const int motorPin = 9;


void setup()
{
  // Установим порт мотора как выходной:

  pinMode(motorPin, OUTPUT);

  // Активируем "Монитор порта":

  Serial.begin(9600);
}


void loop()
{
  // Здесь мы использовали комментарии для отключения некоторых
  // примеров. Чтобы испробовать другой пример, раскомментируйте
  // одну из следующих строк и закомментируйте другие. См функции,
  // для того чтобы узнать что они делают и как работают.

  // motorOnThenOff();
  // motorOnThenOffWithSpeed();
  // motorAcceleration();
     serialSpeed();
}

// Попробуйте разные значения.

void motorOnThenOff()
{
  int onTime = 3000;  // миллисекунд для вращения мотора
  int offTime = 3000; // миллисекунд для простаивания мотора
  
  digitalWrite(motorPin, HIGH); // включить мотор - максимальная скорость
  delay(onTime);                // задержка, для продолжения вращения
  digitalWrite(motorPin, LOW);  // выключить мотор
  delay(offTime);               // задержка, для простаивания мотора
}

// Функция "motorOnThenOffWithSpeed" переключает работу мотора между
// двумя скоростями. Пробуйте разные значения, если интересно.

void motorOnThenOffWithSpeed()
{
  int Speed1 = 200;  // скорость "Speed1" 0 (остановка), 255 (полный ход)
  int Time1 = 3000;  // время "Time1" в миллисекундах
  
  int Speed2 = 50;   // скорость "Speed2" 0 (остановка), 255 (полный ход)
  int Time2 = 3000;  // время "Time2" в миллисекундах
  
  analogWrite(motorPin, Speed1);  // включаем мотор на скорости "Speed1" 
  delay(Time1);                   // продолжаем вращение заданное время
  analogWrite(motorPin, Speed2);  // включаем мотор на скорость "Speed2"
  delay(Time2);                   // продолжаем, заданное время "Time2"
}


// Функция "motorAcceleration" раскручивает двигатель от нуля до
// максимума, и обратно до полной остановки.

void motorAcceleration()
{
  int speed;
  int delayTime = 20; // пауза в миллисекундах
  
  // будем раскручивать мотор, увеличивая скорости от 0 до 255 с паузой в
  // 20 миллисекунд меду каждым шагом (1, пауза, 2, пауза, 3, пауза и.т.д)

  for(speed = 0; speed <= 255; speed++) // шаг, увеличение на единицу
  {
    analogWrite(motorPin,speed);	// установка новой скорости
    delay(delayTime);           	// пауза "delayTime", т.е 20 миллисекунд
  }
  
  // будем останавливать мотор, уменьшая скорость от 255 до 0 с паузой в
  // 20 миллисекунд меду каждым шагом (255, пауза, 254, пауза, 253, пауза ...)

  for(speed = 255; speed >= 0; speed--)
  {
    analogWrite(motorPin,speed);	// установка новой скорости
    delay(delayTime);           	// пауза "delayTime", т.е 20 миллисекунд
  }
}


// Следующая функция позволит вам изменять скорость прямо в окне
// "Монитора порта". Для этого откройте Монитор порта, используя
// значок увеличительного стекла в Arduino IDE, в правом верхнем
// углу окна. Затем введите желаемую скорость в специальном месте
// для ввода текста "Type a speed (0-255) into the box above,", в
// верхней части окна, и нажмите кнопку "Send" (отправить) или 
// "return" (возврат). Двигатель будет работать на заданной вами
// скорости. Допустимый диапазон от 0 до 255.

void serialSpeed()
{
  int speed;
  
  Serial.println("Type a speed (0-255) into the box above,");
  // Т.к. с русским языком в "мониторе порта" существуют некоторые
  // сложности, надписи будут на английском.
  Serial.println("then click [send] or press [return]");
  Serial.println();  // Распечатать пустую строку

  // In order to type out the above message only once,
  // we'll run the rest of this function in an infinite loop:
  // Для того, чтобы вывести сообщение (выше) лишь один раз,
  // Мы будем запускать остальную часть этой функции в
  // бесконечном цикле:
  // Вывод запроса данных осуществляется лишь раз, после этого
  // Функция будет проверять правильность ввода данных по кругу, пока
  // данные не изменятся.

  while(true)
  {
    // Сначала мы проверяем, доступны ли входные данные:
  
    while (Serial.available() > 0)
    {
	  // Если данные есть, выполняем parseInt() для считывания цифр:
      
      speed = Serial.parseInt();
  
      // Поскольку analogWrite() работает с числами от 0 до 255,
      // мы обязательно должны быть уверенны, что число входит в
	  // заданный диапазон. Для этого воспользуемся функцией "constrain".
      // об этой функции мы говорили в опыте №6 "Arduino и Фоторезистор":
  
      speed = constrain(speed, 0, 255);
      
      // Напечатать сообщение для того, чтобы вы знали что число
      // было получено:
      
      Serial.print("Setting speed to ");
      Serial.println(speed);
  
      // И в конце зададим скорость двигателя
      
      analogWrite(motorPin, speed);
    }
  }
}




