#include "_config.h"
#include <DHT.h>
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <LedControl.h>

#define INTERVALO_ENVIO_THINGSPEAK    60000 // intervalo entre envios de dados ao ThingSpeak (em ms)
#define INTERVALO_LEITURA_THINGSPEAK  5000  // intervalo entre leitura de dados do ThingSpeak (em ms)
#define INTERVALO_LEITURA_SOLO        3000 // intervalo entre leitura de dados do sensor de solo (em ms)
#define INTERVALO_RESTART             3600000 // reboot a cada 1h (em ms)
#define FUSO                          -3 // UTC -3:00 Brazil
#define NTP_ADDRESS                   "a.st1.ntp.br" // NTP Server
#define SOIL_SENSOR_PIN               A0
#define WATER_PUMP_PIN                D2
#define DISPLAY_DIN_PIN               D8
#define DISPLAY_CS_PIN                D7
#define DISPLAY_CLK_PIN               D6

char EnderecoAPIThingSpeak[]  = "api.thingspeak.com"; // endereço do thingspeak
long ultimaLeituraSolo = 0;
long ultimaConexaoGravacao = 0;
long ultimaConexaoLeitura = 0;
long ultimoValorSolo = 0;

WiFiClient client;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_ADDRESS, FUSO * 3600, 60000);
LedControl lc=LedControl(DISPLAY_DIN_PIN, DISPLAY_CLK_PIN, DISPLAY_CS_PIN, 0);

void setup()
{
  Serial.begin(9600);
  Serial.println();

  pinMode(WATER_PUMP_PIN, OUTPUT);
  pinMode(SOIL_SENSOR_PIN, INPUT);

  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);

  connectWifi();
}

void loop()
{
  connectWifi();
  
  ArduinoOTA.handle();
  timeClient.update();

  solo();
  irrigacao();
  enviaDados();
  recebeDados();

  delay(2000);

  // restartando a cada 1h ou quando o link cai
  if (client.status() == WL_DISCONNECTED || millis() >= INTERVALO_RESTART)
  {
    ESP.restart();
  }
}


