#define RELAY_IN 2
const int AquaLevelPin = A0;

int AquaOutput = 0;

void setup() {
  // Инициализируем серийный порт со скоростью 9600 бит/с
  Serial.begin(9600);
  //пин реле как выход
  pinMode (RELAY_IN, OUTPUT);
}


void loop() {
  // Читаем значение с датчика уровня жидкости
  int AquaLevel = analogRead(AquaLevelPin);
  AquaOutput = map(AquaLevel, 0, 370, 0, 10);
  // Выводим значение в Serial Monitor
  Serial.print("Уровень жидкости: ");
  Serial.println(AquaOutput);
  
  digitalWrite(RELAY_IN, HIGH);
  // Ждем 1 секунду перед следующим чтением
  delay(1000);
  digitallWrite(RELAY_IN, LOW);
}