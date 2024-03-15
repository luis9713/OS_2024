Solucion del taller #2
Developer: Luis Angel Portillo

#define TMP A0
#define LED 13 
#define MOTOR 12 

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(MOTOR, OUTPUT);
}

void loop() {
  
  float temp = analogRead(TMP) * 0.48828125 - 50;

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" C");

  if (isnan(temp)) {
    Serial.println("Error al leer la temperatura");
    return;
  }

  if (temp < 5.0) {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
  } else if (temp >= 6.0 && temp <= 25.0) {
    digitalWrite(LED, LOW);
  } else if (temp > 25.0) {
    digitalWrite(LED, HIGH);
    digitalWrite(MOTOR, HIGH);
  }
}