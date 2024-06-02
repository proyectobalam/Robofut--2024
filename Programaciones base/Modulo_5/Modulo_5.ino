/*
 **********PROYECTO BALAM 2024************
 *  Módulo #5
 *  Prueba de motores con control de PS4
 *  FASE CREA
 */

#include <PS4Controller.h>

//Incluir libreria del TB6612
#include <TB6612_ESP32.h>

//Definir variables y pines del motor
#define AIN1 18
#define AIN2 4
#define BIN1 27
#define BIN2 14

//Definir salidas pwm de los motores
#define PWMA 12
#define PWMB 13
#define STBY 23

// estas constantes se utilizan para permitirle realizar la configuración del motor
// alinearse con nombres de funciones como forward. El valor puede ser 1 o -1
const int offsetA = 1;
const int offsetB = 1;


// Inicializando motores. La biblioteca le permitirá los motores.
// Si está utilizando funciones como reenviar que toman 2 motores como argumentos puedes escribir nuevas funciones o
// llama a la función más de una vez.

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY,5000 ,8,1 );
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY,5000 ,8,2 );

void setup() {
  Serial.begin(115200); // Iniciar el monitor serial
  PS4.begin("08:d1:f9:89:ab:de"); // Dirección MAC, de la ESP32
  Serial.println("Ready."); 
}

void loop() {
  // Establecer una conexión con el control
  if (PS4.isConnected()) {

/*
    int LStickX = PS4.LStickX();
    if (LStickX != 0) {
      LStickX = map(LStickX, -128, 128, -255, 255);
      Serial.printf("Left Stick x at %d\n", LStickX);
    }
*/
    // Joystick derecho controla el motor derecho
    int LStickY = PS4.LStickY();
    if (LStickY != 0) {
      LStickY = map(LStickY, -128, 128, -255, 255); // Función map con el joystick conviertiendo con valores del motor
      Serial.printf("Left Stick y at %d\n", LStickY);
      motor1.drive(LStickY,10);
    }

/*
    int RStickX = PS4.RStickX();
    if (RStickX != 0) {
      RStickX = map(RStickX, -128, 128, -255, 255);
      Serial.printf("Right Stick x at %d\n", RStickX);
    }
*/
    // Joystick izquierdo controla el motor izquierdo
    int RStickY = PS4.RStickY();
    if (RStickY != 0) {
      RStickY = map(RStickY, -128, 128, -255, 255); // Función map con el joystick convirtiendo con valores del motor
      Serial.printf("Right Stick y at %d\n", RStickY);
      motor2.drive(RStickY,10);
    }
}
  Serial.println("");
  delay(30);

}
