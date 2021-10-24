#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const byte bt_up = 5;
const byte bt_down = 18;
const byte bt_select = 19;

LiquidCrystal_I2C lcd(0x27, 16, 2);
int freq = 100;
byte duty = 50, tensao = 12, ganho = 1, tempo = 5, exitacao = 5, tela = 1;
bool reset = LOW, status_backlight = HIGH;

void tela_inicializacao() {
  lcd.clear();
  freq = 100;
  duty = 50, tensao = 12, ganho = 1, tempo = 5, exitacao = 5, tela = 1;
  lcd.setCursor(0, 0);
  lcd.print("PECT - SYSTEM");
  lcd.setCursor(10, 1);
  lcd.print("V 1.0");
  delay(3000);
  for (byte i = 0; i <= 15; i++) {
    lcd.scrollDisplayLeft();
    delay(300);
  }
  Serial.println(tela);
  tela_inicial();
}
void tela_inicial() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("F ");
  lcd.setCursor(2, 0);
  lcd.print(freq);
  // ##################
  lcd.setCursor(7, 0);
  lcd.print("D ");
  lcd.setCursor(9, 0);
  lcd.print(duty);
  // ##################
  /*
    lcd.setCursor(12, 0);
    lcd.print("T ");
    lcd.setCursor(14, 0);
    lcd.print(tempo);
  */
  // ##################
  lcd.setCursor(12, 0);
  lcd.print("T ");
  lcd.setCursor(14, 0);
  lcd.print(tensao);
  // ##################
  lcd.setCursor(0, 1);
  lcd.print("G ");
  lcd.setCursor(2, 1);
  lcd.print(ganho);
  // ##################
  lcd.setCursor(5, 1);
  lcd.print("E ");
  lcd.setCursor(7, 1);
  lcd.print(exitacao);
  // ##################
}
void tela_freq() {
  lcd.setCursor(0, 0);
  lcd.print("Freq ");
  lcd.setCursor(5, 0);
  lcd.print(freq);
}
void tela_duty() {
  lcd.setCursor(0, 0);
  lcd.print("Duty Cicle ");
  lcd.setCursor(12, 0);
  lcd.print(duty);
}
void tela_tensao() {
  lcd.setCursor(0, 0);
  lcd.print("Tensao ");
  lcd.setCursor(8, 0);
  lcd.print(tensao);
}
void tela_ganho() {
  lcd.setCursor(0, 0);
  lcd.print("Ganho ");
  lcd.setCursor(7, 0);
  lcd.print(ganho);
}
void tela_exitacao() {
  lcd.setCursor(0, 0);
  lcd.print("Exitacao ");
  lcd.setCursor(10, 0);
  lcd.print(exitacao);
}
void tela_reset() {
  lcd.setCursor(0, 0);
  lcd.print("Resetar ?");
}
void tela_backlight(){
  lcd.setCursor(0, 0);
  if (status_backlight){
  lcd.print("Luz de fundo: ON");
  }else{
    lcd.print("Luz de fundo: OFF");
  }
}
void trocar_tela() {
  switch (tela) {
    case 1: // tela inicial
      lcd.clear();
      tela_inicial();
      break;
    case 2: // alterar freq
      lcd.clear();
      tela_freq();
      break;
    case 3: // alterar duty
      lcd.clear();
      tela_duty();
      break;
    case 4: // alterar tensao
      lcd.clear();
      tela_tensao();
      break;
    case 5: // alterar ganho
      lcd.clear();
      tela_ganho();
      break;
    case 6: // alterar exitacao
      lcd.clear();
      tela_exitacao();
      break;
    case 7: // alterar reset
      lcd.clear();
      tela_reset();
      break;
    case 8: // alterar backlight
      lcd.clear();
      tela_backlight();
      break;
  }
}
void entrar_tela() {
  switch (tela) {
    case 1: // tela inicial
      lcd.clear();
      tela = 1;
      tela_inicial();
      break;
    case 2: // alterar freq
      lcd.clear();
      tela_freq();
      while (digitalRead(bt_select) == HIGH) {
        if (digitalRead(bt_up) == LOW) {
          if ( freq >= 1000) {
            freq = 0;
          } else {
            freq = freq + 10;
          }
          delay(100);
          lcd.clear();
          tela_freq();
        }
        if (digitalRead(bt_down) == LOW) {
          if ( freq <= 0) {
            freq = 1000;
          } else {
            freq = freq - 10;
          }
          delay(100);
          lcd.clear();
          tela_freq();
        }
      }
      tela = 1;
      tela_inicial();
      delay(100);
      break;
    case 3: // alterar duty
      lcd.clear();
      tela_duty();
      while (digitalRead(bt_select) == HIGH) {
        if (digitalRead(bt_up) == LOW) {
          if ( duty == 99) {
            duty = 1;
          } else {
            duty++;
          }
          delay(100);
          lcd.clear();
          tela_duty();
        }
        if (digitalRead(bt_down) == LOW) {
          if ( duty == 1) {
            duty = 99;
          } else {
            duty--;
          }
          delay(100);
          lcd.clear();
          tela_duty();
        }
      }
      tela = 1;
      tela_inicial();
      delay(100);
      break;
    case 4: // alterar tensao
      lcd.clear();
      tela_tensao();
      while (digitalRead(bt_select) == HIGH) {
        if (digitalRead(bt_up) == LOW) {
          if ( tensao == 30) {
            tensao = 12;
          } else {
            tensao++;
          }
          delay(100);
          lcd.clear();
          tela_tensao();
        }
        if (digitalRead(bt_down) == LOW) {
          if ( tensao == 12) {
            tensao = 30;
          } else {
            tensao--;
          }
          delay(100);
          lcd.clear();
          tela_tensao();
        }
      }
      tela = 1;
      tela_inicial();
      delay(100);
      break;
    case 5: // alterar ganho
      lcd.clear();
      tela_ganho();
      while (digitalRead(bt_select)) {
        if (digitalRead(bt_up) == LOW) {
          if ( ganho == 5) {
            ganho = 1;
          } else {
            ganho++;
          }
          delay(100);
          lcd.clear();
          tela_ganho();
        }
        if (digitalRead(bt_down) == LOW) {
          if ( ganho == 1) {
            ganho = 5;
          } else {
            ganho--;
          }
          delay(100);
          lcd.clear();
          tela_ganho();
        }
      }
      tela = 1;
      tela_inicial();
      delay(100);
      break;
    case 6: // alterar exitacao
      lcd.clear();
      tela_exitacao();
      while (digitalRead(bt_select) == HIGH) {
        if (digitalRead(bt_up) == LOW) {
          if ( exitacao == 10) {
            exitacao = 0;
          } else {
            exitacao++;
          }
          delay(100);
          lcd.clear();
          tela_exitacao();
        }
        if (digitalRead(bt_down) == LOW) {
          if ( exitacao == 0) {
            exitacao = 10;
          } else {
            exitacao--;
          }
          delay(100);
          lcd.clear();
          tela_exitacao();
        }
      }
      tela = 1;
      tela_inicial();
      delay(100);
      break;
    case 7: // alterar reset
      lcd.clear();
      tela_reset();
      lcd.setCursor(0, 1);
      lcd.print("S(UP)/N(DOWN)");
      reset = LOW;
      while (reset == LOW) {
        if (digitalRead(bt_up) == LOW) {
          tela_inicializacao();
          reset = HIGH;
        }
        if (digitalRead(bt_down) == LOW) {
          tela = 1;
          lcd.clear();
          tela_inicial();
          reset = HIGH;
        }
        delay(100);
      }
      break;
    case 8: // alterar backlight
      lcd.clear();
      tela_backlight();
      lcd.setCursor(0, 1);
      lcd.print("ON(UP)/OFF(DOWN)");
      while (digitalRead(bt_select) == HIGH) {
        if (digitalRead(bt_up) == LOW) {
          lcd.backlight();
          status_backlight = HIGH;
        }
        if (digitalRead(bt_down) == LOW) {
          lcd.noBacklight();
          status_backlight = LOW;
        }
        delay(100);
        tela = 1;
        lcd.clear();
        tela_inicial();
      }
      break;
  }
}

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();

  tela_inicializacao();
  pinMode(bt_up, INPUT_PULLUP);
  pinMode(bt_down, INPUT_PULLUP);
  pinMode(bt_select, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(bt_up) == LOW) { // UP
    Serial.println("UP");
    if ( tela == 8) {
      tela = 1;
    } else {
      tela++;
    }
    delay(100);
    Serial.println(tela);
    trocar_tela();
  }

  if (digitalRead(bt_down) == LOW) { // DOWN
    Serial.println("DOWN");
    if ( tela == 1) {
      tela = 8;
    } else {
      tela--;
    }
    delay(100);
    Serial.println(tela);
    trocar_tela();
  }

  if (digitalRead(bt_select) == LOW) { // OK
    Serial.println("Entrando");
    delay(400);
    entrar_tela();
  }

  delay(100);
}
