#define RELAY_IN 2
const int AquaLevelPinUp = A0;// s - желтый
const int AquaLevelPinDown = A1;// s - желтый

int AquaOutputUp = 0;
int AquaOutputDown = 0;

int aquaStart = 0;

void setup() {
  // Инициализируем серийный порт со скоростью 9600 бит/с
  Serial.begin(9600);
  //пин реле как выход
  pinMode (RELAY_IN, OUTPUT);
}


void loop() {
  // Читаем значение с датчиков уровня жидкости верхнего и нижнего
  int AquaLevelUp = analogRead(AquaLevelPinUp);
  int AquaLevelDown = analogRead(AquaLevelPinDown);


  AquaOutputUp = map(AquaLevelUp, 0, 370, 0, 10);
  AquaOutputDown = map(AquaLevelDown, 0, 370, 0, 10);
  // Выводим значение в Serial Monitor
  Serial.print("Верхний уровень жидкости: ");
  Serial.println(AquaOutputUp);
  Serial.print("Нижний уровень жидкости: ");
  Serial.println(AquaOutputDown);
  delay (1000);
  //digitalWrite(RELAY_IN, HIGH);
  // Ждем 1 секунду перед следующим чтением
  //delay(1000);
  //if (AquaOutput < 4){
  //  digitalWrite(RELAY_IN, HIGH); // включаем реле
  //}
  //else{
  //  digitalWrite(RELAY_IN, LOW);
  //}
  //digitalWrite(RELAY_IN, LOW);
  //delay(1000);
}