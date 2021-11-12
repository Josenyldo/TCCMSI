
#include <Wire.h>
#include "SSD1306Wire.h"
SSD1306Wire  display(0x3c, D2, D3);
void setup()
{
  Serial.begin(115200);
  display.init();
  display.flipScreenVertically();
}
void texto()
{
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setFont(ArialMT_Plain_16);
  display.drawString(63, 10, "Desculpe");
  display.drawString(63, 26, "Brito");
  display.display();
}
void horario()
{
  //Apaga o display
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  //Seleciona a fonte
  display.setFont(ArialMT_Plain_16);
  display.drawString(63, 10, "Hora");
  display.display();
}

void loop()
{
  texto();
  delay(3000);
  horario();
  delay(3000);
}
