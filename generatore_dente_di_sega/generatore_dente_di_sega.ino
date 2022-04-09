/*
 * Programma per la generazione di un segnale a dente di sega
 * con Arduino Nano o Arduino UNO, su Port D0..D7 (uscite 0..7).
 * 
 * Attenzione, non è possibile usare la linea seriale per il debug,
 * che sarebbe situata sui bit Portg D0 e Port D1.
 * 
 * Mediante il trimmer è possibile modificare la frequenza del segnale.
 * 
 * Il sintetizzatore audio con DAC a 8 bit, basato su Arduino Nano 
 * e dotato di amplificato audio da 1 watt è acquistabile su:
 * https://shop.fremsoft.it/prodotto/sintetizzatore-audio-dac-ampli-1watt-arduino-nano/
 *
 * Visualizza il progetto integrale su YouTube: 
 * https://youtu.be/ef_y3xCBzfw
 *  
 */

#define SHUTDOWN   8   /* attivo basso 0=spento; 1= acceso */
#define TRIMMER    A0  /* trimmer 10K */

int analogOutput;

void setup() {

  pinMode ( 0, OUTPUT );
  pinMode ( 1, OUTPUT );
  pinMode ( 2, OUTPUT );
  pinMode ( 3, OUTPUT );
  pinMode ( 4, OUTPUT );
  pinMode ( 5, OUTPUT );
  pinMode ( 6, OUTPUT );
  pinMode ( 7, OUTPUT );

  PORTD = 0;
  
  pinMode ( SHUTDOWN, OUTPUT );
  digitalWrite( SHUTDOWN, LOW );

  /* azzeramento delle variabili globali */
  analogOutput = 0;
  
}

void loop() {

  analogOutput = (analogOutput + 1) & 0xFF;

  PORTD = analogOutput;

  delayMicroseconds( analogRead( TRIMMER ) );
  
}
