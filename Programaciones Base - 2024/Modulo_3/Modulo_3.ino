/*
 **********PROYECTO BALAM 2024************
 *  Módulo #3
 *  Prueba de motores con Dabble D-Pad
 *  FASE CREA
 */

//Incluir libreria del TB6612
#include <TB6612_ESP32.h>
//Incluir libreria del Dabble
#include <DabbleESP32.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

//Motor A
#define PWMA 15
#define AIN1 18
#define AIN2 5

//Motor A1
#define PWMA1 12
#define AIN11 32
#define AIN22 33

//Motor B
#define PWMB 2
#define BIN1 27
#define BIN2 14

//Motor B1
#define PWMB1 13
#define BIN11 25
#define BIN22 26

#define STBY 0
#define STBY1 22

const int offsetA = 1;
const int offsetB = 1;

const int offsetA1 = 1;
const int offsetB1 = 1;

//Iniciar motores
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY,5000 ,8,1 );
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY,5000 ,8,2 );

//Iniciar motores
Motor motor11 = Motor(AIN11, AIN22, PWMA1, offsetA1, STBY1,5000 ,8,4 );
Motor motor22 = Motor(BIN11, BIN22, PWMB1, offsetB1, STBY1,5000 ,8,5 );

void setup() {
  Serial.begin(115200);   // Iniciar el monitor serial  
  Dabble.begin("PruebaBalam2024");       //Nombre del BT
}

void loop() {

  Dabble.processInput(); // Esperando conexión por BT            
  Serial.println("KeyPressed: ");
  
  //Utilización de la XPAD (cruzeta) del control por DABBLE
  if (GamePad.isUpPressed())
  {
    forward(motor1, motor2, 200);
    Serial.println("Adelante");
    delay(10);
  }

  if (GamePad.isDownPressed())
  {
     back(motor1, motor2, 200);
     Serial.println("Atrás");
     delay(10);
  }

  if (GamePad.isLeftPressed())
  {
     left(motor1, motor2, 200);
     Serial.println("Izquierda");
     delay(10);
    
  }
  if (GamePad.isRightPressed())
  {
     right(motor1, motor2, 200);
     Serial.println("Derecha");
     delay(10);
  }
  //Bóton "X" para detener
  if (GamePad.isCrossPressed())
  {
    Serial.print("Cross");
     brake(motor1, motor2);
     Serial.println("Detener");
     delay(10);
  }
    if (GamePad.isSquarePressed())
  {
    Serial.print("Square");
    forward(motor11, motor22, 200);
    Serial.println("Activado disparador");
    delay(10);
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("Circle");
     brake(motor11, motor22);
    Serial.println("Desactivado disparador");
    delay(10);
  }

  if (GamePad.isTrianglePressed())
  {
    Serial.print("Triangle");   
  }

  if (GamePad.isStartPressed())
  {
    Serial.print("Start");
  }

  if (GamePad.isSelectPressed())
  {
    Serial.print("Select");
  }

  /*
  Serial.print('\t');

  int a = GamePad.getAngle();
  Serial.print("Angle: ");
  Serial.print(a);
  //Serial.print('\t');
  
  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println();
  */
}
 
