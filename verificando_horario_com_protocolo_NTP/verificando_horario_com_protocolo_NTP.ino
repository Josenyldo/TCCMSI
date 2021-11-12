//REFERENTE AOS DISPLAYS OLED
#include <Wire.h>
#include "SSD1306Wire.h"
SSD1306Wire  display(0x3c, D2, D3);

//REFERENTE AO CLIENTNTP
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>


const char *ssid     = "LG K9 TV_2609";
const char *password = "";

//diferença em segundos entre o brazil e o referencial (UTC)
int diffUTCBrazil = -10800;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP,-10800);


void setup()
{
  Serial.begin(115200);

  //REFERENTE AOS DISPLAYS OLED
  display.init();
  display.flipScreenVertically();

  //REFERENTE AO CLIENTNTP
  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
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
  timeClient.update();
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setFont(ArialMT_Plain_16);
  display.drawString(63, 10, timeClient.getFormattedTime());
  display.display();
}

void loop()
{
  texto();
  delay(3000);
  horario();
  delay(3000);
}
