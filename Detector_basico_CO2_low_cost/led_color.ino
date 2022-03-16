void setLED(LED_COLOR color) {
  analogWrite(LED_Rojo_pin, 0);   // Reseteamos todos los colores a cero
  analogWrite(LED_Verde_pin,0);
  analogWrite(LED_Ama_pin, 0);
  switch (color) {              // Activamos los diferentes colores
    case LED_Rojo:
      analogWrite (LED_Rojo_pin, 255);
      break;
    case LED_Verde: 
      analogWrite(LED_Verde_pin, 255);
      break;
    case LED_Ama: 
      analogWrite(LED_Ama_pin, 255);
      break;
     }
}
