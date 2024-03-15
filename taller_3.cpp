Solucion del taller #3
Developer: Luis Angel Portillo

#include <LiquidCrystal.h>
#define TMP A0
#define LED 13
#define MOTOR 10

int seconds = 0;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup(){
lcd_1.begin(16, 2);
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(MOTOR, OUTPUT);
  
  
  lcd_1.print("Hello word!");
}

void loop(){
  float temp = analogRead(TMP) * 0.48828125 - 50;
  
lcd_1.setCursor(0, 1);
  lcd_1.print(seconds);
  delay(1000);
  seconds += 1;
  lcd_1.print(" ");
  lcd_1.print(temp);
  lcd_1.print("   ");
  
  

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" C");
  
  if (isnan(temp)) {
    Serial.println("Error al leer la temperatura");
    return;
  }

  if (temp < 10.0){
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
    digitalWrite(MOTOR,LOW);
  } else if (temp >=11.0 && temp <= 24.0) {
    digitalWrite(LED, LOW);
    digitalWrite(MOTOR,LOW);
  } else if (temp > 26.0) {
    digitalWrite(LED, HIGH);
    digitalWrite(MOTOR, HIGH);
  }
}
 