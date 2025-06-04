#define RELAY_PIN 2
const int AquaLevelPinUp = A0;// s - желтый
const int AquaLevelPinDown = A1;// s - желтый

const int UPPER_THRESHOLD = 7;  // Значение, когда жидкость достигла верхнего уровня
const int LOWER_THRESHOLD = 19;  // Значение, когда жидкость достигла нижнего уровня



int AquaOutputUp = 0;
int AquaOutputDown = 0;

int aquaStart = 0;

void setup() {
  // Инициализируем серийный порт со скоростью 9600 бит/с
  Serial.begin(9600);
  //пин реле как выход
  pinMode (RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);  // Изначально насос выключен
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

  
    // Логика управления насосом
  if (digitalRead(RELAY_PIN) == HIGH) {
    // Насос включен - проверяем, достигнут ли верхний уровень
    if (AquaOutputUp > UPPER_THRESHOLD) {
      digitalWrite(RELAY_PIN, LOW);  // Выключаем насос
      Serial.println("Насос отключен - верхний уровень жидкости");
    }
  } else {
    // Насос выключен - проверяем, опустился ли уровень до нижней метки
    if (AquaLevelDown < LOWER_THRESHOLD) {
      digitalWrite(RELAY_PIN, HIGH);  // Включаем насос
      Serial.println("Насос включен - нижний уровень жидоксти");
    }
  }
  
}
//test
