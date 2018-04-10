int solo()
{
  ultimoValorSolo = FazLeituraUmidade();
  ultimaLeituraSolo = millis();

  Serial.print("- Controlando umidade de solo: ");
  Serial.print(ultimoValorSolo);
  Serial.println("%");

  return ultimoValorSolo;
}

//Função: faz a leitura do nível de umidade
//Parâmetros: nenhum
//Retorno: umidade percentual (0-100)
//Observação: o ADC do NodeMCU permite até, no máximo, 3.3V. Dessa forma,
//            para 3.3V, obtem-se (empiricamente) 978 como leitura de ADC
// @from https://www.filipeflop.com/blog/planta-iot-com-esp8266-nodemcu/
float FazLeituraUmidade(void)
{
    int ValorADC;
    float UmidadePercentual;
 
     ValorADC = analogRead(SOIL_SENSOR_PIN);   //978 -> 3,3V
     
     Serial.print("- Leitura ADC: ");
     Serial.println(ValorADC);
 
     //Quanto maior o numero lido do ADC, menor a umidade.
     //Sendo assim, calcula-se a porcentagem de umidade por:
     //      
     //   Valor lido                 Umidade percentual
     //      _    0                           _ 100
     //      |                                |   
     //      |                                |   
     //      -   ValorADC                     - UmidadePercentual 
     //      |                                |   
     //      |                                |   
     //     _|_  978                         _|_ 0
     //
     //   (UmidadePercentual-0) / (100-0)  =  (ValorADC - 978) / (-978)
     //      Logo:
     //      UmidadePercentual = 100 * ((978-ValorADC) / 978)  
     UmidadePercentual = 100 * ((978-(float)ValorADC) / 978);
 
     return UmidadePercentual;
}
