void irrigacao()
{
  if (ultimoValorSolo >= SOIL_MEASURE_LIMIT) {
    drawHappyFace();
    
    return;
  }

  drawNeutralFace();

  startPump();

  drawHappyFace();
}

void startPump()
{
  Serial.println("- ligando bomba");
  digitalWrite(WATER_PUMP_PIN, HIGH); 

  delay(WATER_TIME * 1000);

  Serial.println("- desligando bomba");
  digitalWrite(WATER_PUMP_PIN, LOW);    
}

