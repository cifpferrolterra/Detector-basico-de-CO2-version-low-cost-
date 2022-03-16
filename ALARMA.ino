void alarma() {
  if (repite==0 && estadoalarma==1)
  { for (int i=0; i<ntonos; i++){
    tone (buzzer,tonos[i]);
    delay (150);
            }
  noTone (buzzer);
  delay (200);
  repite = true;
  }
 else   {
  noTone (buzzer);
        }
}
