/*
  Blink (неблокирующий) — мигание встроенным светодиодом без delay().

  В отличие от классического Blink, loop() здесь никогда не «зависает»:
  интервал отсчитывается по millis(), поэтому между переключениями
  светодиода процессор свободен и может выполнять любой другой код
  (опрос кнопок и датчиков, связь, дисплеи и т.д.).

  Работает на любых платах Arduino-совместимого семейства
  (Uno, Nano, Mega, ESP8266, ESP32 ...).
*/

const uint8_t  LED_PIN         = LED_BUILTIN;  // встроенный светодиод (на Uno/Nano — D13)
const uint32_t TOGGLE_INTERVAL = 500;          // пауза между переключениями, мс

bool     ledState   = LOW;
uint32_t lastToggle = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, ledState);
}

void loop() {
  // Беззнаковая разность корректна даже при переполнении millis() (~49 суток на 16 МГц AVR)
  if (millis() - lastToggle >= TOGGLE_INTERVAL) {
    lastToggle += TOGGLE_INTERVAL;  // += вместо = millis() не накапливает дрейф такта
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
  }

  // Сюда можно добавлять любой другой код — мигалка ему не помешает.
}
