void startPump()
{
  Serial.println("- ligando bomba");
  digitalWrite(WATER_PUMP_PIN, HIGH); 

  delay(WATER_TIME * 1000);

  stopPump();
}

void stopPump()
{
  Serial.println("- desligando bomba");
  digitalWrite(WATER_PUMP_PIN, LOW);    
}
