const int liquidLevelPin = A0;

void setup() {
  // Инициализируем серийный порт со скоростью 9600 бит/с
  Serial.begin(9600);
}

void loop() {
  // Читаем значение с датчика уровня жидкости
  int liquidLevel = analogRead(liquidLevelPin);
  
  // Выводим значение в Serial Monitor
  Serial.print("Уровень жидкости: ");
  Serial.println(liquidLevel);
  
  // Ждем 1 секунду перед следующим чтением
  delay(1000);
}