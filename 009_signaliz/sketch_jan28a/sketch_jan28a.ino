int ledPin = 13;
int buttonOnPin = 12;
int shockKy002Sensor = 11;

void setup() {
  Serial.begin(9600);
  pinMode (ledPin, OUTPUT);  
  pinMode (buttonOnPin, INPUT);
  pinMode (shockKy002Sensor, INPUT);
}

void loop() {

    int shockKy002SensorValue = digitalRead(shockKy002Sensor); // чтение состояния датчика
      if (shockKy002SensorValue == LOW) // когда датчик детектирует удар, светодиод загорается 
      {
        digitalWrite (ledPin, HIGH);
        Serial.println(shockKy002SensorValue);
        
      }
      else
      {
        digitalWrite (ledPin, LOW);
      }
      
}
