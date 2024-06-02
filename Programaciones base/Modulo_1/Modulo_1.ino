/*
 **********PROYECTO BALAM 2024************
 *  Módulo #1
 *  Prueba de motores
 *  FASE CREA
 */

int STBY = 23; //standby (Activación para el módulo TB6612FNG)

//Motor A
int PWMA = 12; //Velocidad de motor por PWM 
int AIN1 = 18; //Dirección
int AIN2 = 4; //Dirección

//Motor B
int PWMB = 13; //Velocidad de motor por PWM 
int BIN1 = 27; //Dirección
int BIN2 = 14; //Dirección

void setup(){
  //Declaración de sálidas
  pinMode(STBY, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  //Inició del monitor serial
  Serial.begin(115200);
}

void loop(){
  digitalWrite(STBY, HIGH); //activación de standbay
  digitalWrite(PWMA, HIGH);
  digitalWrite(PWMB, HIGH);
  
  //Pin del motor, velocidad del motor
  //Hacia adelante
  analogWrite(AIN1, 150);
  analogWrite(AIN2, 0);
  analogWrite(BIN1, 150);
  analogWrite(BIN2, 0);
  Serial.println("Adelante");
  delay(5000);
  
  //Hacia atrás
  analogWrite(AIN1, 0);
  analogWrite(AIN2, 150);
  analogWrite(BIN1, 0);
  analogWrite(BIN2, 150);
  Serial.println("Atrás");
  delay(5000);
  
  //Hacia derecha
  analogWrite(AIN1, 150);
  analogWrite(AIN2, 0);
  analogWrite(BIN1, 0);
  analogWrite(BIN2, 150);
  Serial.println("Derecha");
  delay(5000);
  
  //Hacia izquierdo
  analogWrite(AIN1, 0);
  analogWrite(AIN2, 150);
  analogWrite(BIN1, 150);
  analogWrite(BIN2, 0);
  Serial.println("Izquierda");
  delay(5000);
}
