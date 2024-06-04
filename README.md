# Robofut-2024


<div>
    <div align=center>
        <img src="https://github.com/proyectobalam/robofut2024/blob/main/Imagenes/_DSC5055.jpg" alt="Robofut 2024">
    </div>
</div>

## Instalación de la Tarjeta ESP32

Para la instalación en Arduino IDE debemos seguir los siguientes pasos:

1. Abrir ARDUINO IDE
2. Debemos ir a la pestaña ***Archivo***->***Preferencias***.
	- En la pestaña ***Ajustes*** buscamos la opción: ***Gestor de URLs Adicionales de Tarjetas:***
	- Pegamos la siguiente URL: `https://dl.espressif.com/dl/package_esp32_index.json`
	- Luego presionamos la opción ***OK*** y automáticamente se cerrará la ventana.
3. Debemos ir a la pestaña ***Herramientas***->***Placa***->***Gestor de tarjetas***.
	- Colocamos en la barra de búsqueda ***ESP32***.
	- Seleccionamos la opción que nos muestre ***ESP32 Dev Module***.
	- Instalamos y luego presionamos la opción de ***Cerrar***.

Con esto tendremos completa la instalación de nuestra tarjeta ESP32 y lista para ser programada.	 

<div>
    <div align=center>
        <img src="https://github.com/proyectobalam/robofut2024/blob/main/Imagenes/_DSC5092.jpg" alt="Robofut 2024">
    </div>
</div>

## Pinout

### Voltaje de alimentación
Nombre | GPIO 
--- | --- 
VCC | 5VDC a 12VDC
VSS | GND

### Motores de movimiento (M1 & M2)
Nombre | Motor |GPIO 
--- | --- | --- 
AIN_1 | motor1 | 18
AIN_2 | motor2 | 5
PWMA  | motorA | 15
BIN_1 | motor1 | 27
BIN_2 | motor2 | 14
PWMB  | motorB | 2

### Motores de disparador (M3 & M4)

Nombre | Motor |GPIO 
--- | --- | --- 
AIN_11 | motor 3 | 32
AIN_22 | motor 3 | 33
PWMA1  | motorA  | 12
BIN_11 | motor 4 | 25
BIN_22 | motor 4 | 26
PWMB1  | motorB  | 13

## Manejo de motores
Es muy importante que puedas comprender el manejo de los motores realizando un control digital binario (HIGH y LOW) y un control con PWM (valores entre 0 - 255).

Para comprender mejor el tema es recomendable que puedas revisar la hoja de datos de Sparkfun que es el fabricante del módulo TB6612FNG.

**Recuerda que la libreria la puedes encontrar en la parte de arriba junto a las programaciones de ejemplo**.

<div>
    <div align=center>
        <img src="https://github.com/proyectobalam/robofut2024/blob/main/Imagenes/_DSC5059.jpg" alt="Robofut 2024">
    </div>
</div>

## Recomendaciones

1. Si tu tarjeta ESP32 esta conectada a la computadora apaga el switch de encendido de la placa de tu robofut para no dañarla. 
2. Cuando pongás en acción tu RoboFut recuerda tener cargadas tu baterias para un mejor funcionamiento.
3. Revisa tus conexiones siempre antes de programar.
