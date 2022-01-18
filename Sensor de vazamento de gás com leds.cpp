#include <LiquidCrystal.h>

#define PINOGAS A5
#define ALARME 7

#define LEDVERDE 9
#define LEDAMARELO 10
#define LEDVERMELHO 8

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int limiteLeitura = 300;

void setup() {
    pinMode( PINOGAS ,INPUT);
    pinMode( ALARME , OUTPUT);

    pinMode( LEDVERDE , OUTPUT);
    pinMode( LEDAMARELO , OUTPUT);
    pinMode( LEDVERMELHO , OUTPUT);

    lcd.begin(16, 2);
    lcd.print("NIVEL DE GAS");
}

void loop() {

    float valor = analogRead(PINOGAS);  
    lcd.setCursor(0, 1);

    lcd.print("VALOR:");
    lcd.print(valor);

    if (valor > limiteLeitura){
        tone(ALARME,700);
        lcd.setCursor(15, 1);  

    if (valor > limiteLeitura + 100) {
        lcd.print("D");
        digitalWrite(LEDAMARELO,LOW);
        digitalWrite(LEDVERMELHO,HIGH);
    }

    else {
        lcd.print("H");
        digitalWrite(LEDAMARELO,HIGH);
        digitalWrite(LEDVERMELHO,LOW);
    }

    digitalWrite(LEDVERDE,LOW);
  }

  else {
    noTone(ALARME);
    lcd.setCursor(15, 1);  
    lcd.print("N");
    digitalWrite(LEDVERMELHO,LOW);
    digitalWrite(LEDAMARELO,LOW);
    digitalWrite(LEDVERDE,HIGH);
  }
  
   delay (1000);
}