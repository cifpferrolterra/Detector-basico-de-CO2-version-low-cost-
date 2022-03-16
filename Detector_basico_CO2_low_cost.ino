/**
 *  Monitor de CO2 para interiores con sensor de (MH-Z19B)
 *  Monitoriza el nivel de CO2 en un espacio cerrado. Primero advierte y luego emite una alarma en caso de que el nivel de CO2 alcance un nivel no aceptable.
 *  La informacion se presenta en una de pantalla de 4 dígitos, una iluminación LED ademas un zumbador avisa al sobrepasar un cierto nivel especifcio.
 *  Su alimentacion será mediante una fuente USB de 5V.
 */
#include <SoftwareSerial.h>                                
#include <MHZ19.h>
#include <TM1637Display.h>
#define RX_PIN 10                                         // pin 10 al Rx pin sensor MHZ19
#define TX_PIN 11                                         // pin 11 al Tx pin sensor MHZ19
#define BAUDRATE 9600                                     // Velocidad en baudios para puerto serie del sensor MH-Z19 (no cambiar)
#define DISPLAY_CLK_PIN 9                                 // Pines de conexión del módulo Display TM1637 (pines digitales CLK = 9 ,DIO = 8)
#define DISPLAY_DIO_PIN 8
#define LED_Verde_pin 6                                   // Pin 6 conexión del LED  color Verde
#define LED_Ama_pin 5                                     // Pin 5 conexión del LED  color Amarillo
#define LED_Rojo_pin 3                                    // Pin 3 conexión del LED  color Rojo
#define T_lectura_sensor 2e3                              // MH-Z19 tiempo entre lecturas del sensor
int int_silen=4;                                          // Pin 4 interruptor de silencio para alarma 
int buzzer=2;                                             // Pin 2 conexión del Buzzer
int ntonos=12;
int tonos[ ]={261,277,294,311,330,349,370,392,415,440,466,494};
boolean valor = false;
boolean estadoalarma = false;
boolean repite = false;




//
//----------------------------------------------------------------------  inicializamos sensor y display -----------------------------------
MHZ19 myMHZ19;                                             
SoftwareSerial mySerial(RX_PIN, TX_PIN);                   
TM1637Display display(DISPLAY_CLK_PIN, DISPLAY_DIO_PIN);
unsigned long Dato_tempo = 0;
int CO2 = 0;
enum LED_COLOR {LED_Rojo, LED_Verde, LED_Ama};

///----------------------------------------------------------------------------------------- configuraciones -----------------------
void setup() {
    Serial.begin(9600);                                    
    mySerial.begin(BAUDRATE);                                
    myMHZ19.begin(mySerial);                             
    myMHZ19.autoCalibration(true);                                 
    pinMode(int_silen,INPUT_PULLUP);
    pinMode(buzzer,OUTPUT);
    display.setBrightness(0x0f);
    }
// ----------------------------------------------------- programa principal --------------------------------------------------------------
void loop() {  if (millis() - Dato_tempo >= T_lectura_sensor)
  {
//--- Obtener la medición de CO2 actual como ppm----------   
    CO2 = myMHZ19.getCO2();         // Solicitar CO2 (como ppm)
    Serial.print("CO2 (ppm): ");                      
    Serial.println(CO2);    
    coloresled();
    valor = digitalRead(int_silen);
    if(valor == true){
    (estadoalarma = 1);
    }else {  
    (estadoalarma = 0);   
    }
    Serial.print("valor int alar: ");
    Serial.println(valor);
    Serial.print("estado alarma act: ");
    Serial.println(estadoalarma); 
    Serial.print("repite ya sono:  ");
    Serial.println(repite);   
    
    display.showNumberDec(CO2,false); 
    Dato_tempo = millis();
  }
   
}
