void coloresled() {
  if (CO2 < 700) {
    setLED(LED_Verde);
    repite = false;
    Serial.println("Se activara el led en Verde");
    return;
  } 
  if (CO2 < 1200) {
    Serial.println("Se activara el led en Amarillo");
    repite = false;
    setLED(LED_Ama);
    return;
  }
  setLED(LED_Rojo);
    alarma();  
    Serial.println("Se activara el led en Rojo");  
}
