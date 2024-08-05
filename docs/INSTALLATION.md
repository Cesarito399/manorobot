
# Instalación y Configuración del Proyecto de Prótesis de Mano Robótica

## Componentes de Hardware

- **Microcontrolador Arduino**
  - Modelo sugerido: Arduino Uno o Arduino Nano.

- **Microservomotores (5 unidades)**
  - Modelos sugeridos: SG90 o MG90S.

- **Módulo EMG**
  - Modelo sugerido: MyoWare Muscle Sensor.

- **Baterías de 9V (2 unidades)**
  - Utilizadas para alimentar el sistema.

- **Protoboard y cables de conexión**

## Especificaciones Eléctricas

- **Voltaje de Entrada (Vs):** ±3.5V mínimo, ±5V normal, ±18V máximo.
- **Ganancia Configurada:** `Ganancia = 207 * (x/1KΩ)`.
- **Voltaje de Salida:** Entre 0V y +Vs.
- **Voltaje de Entrada Diferencial:** 0mV mínimo, 2-5mV normal, máximo +Vs/Ganancia.

## Montaje del Hardware

1. **Conexión del Módulo EMG:**
   - **+Vs:** Conecta al terminal positivo de la primera batería de 9V.
   - **GND:** Conecta a la línea GND común.
   - **-Vs:** Conecta al terminal positivo de la segunda batería de 9V.
   - **SIG:** Conecta al pin A0 del Arduino.
   - **GND:** Asegúrate de que todos los componentes compartan una conexión común a tierra (GND).

2. **Conexión de los Servomotores:**
   - Conecta los pines de señal de los cinco servos a los pines PWM disponibles en el Arduino (ej., 3, 5, 6, 9, 10).
   - Conecta los pines de potencia a una fuente adecuada y los pines de tierra a la línea GND común.

## Componentes de Software

- **Arduino IDE**
  - Descarga la última versión desde [el sitio oficial de Arduino](https://www.arduino.cc/en/software).

- **Bibliotecas de Arduino**
  - **Servo.h:** Incluye con `#include <Servo.h>`.
  - **Procesamiento de señales EMG:** Implementar funciones personalizadas para procesar las señales del módulo EMG.

## Configuración del Software

1. **Instala y abre el Arduino IDE.**
2. **Conecta tu Arduino al ordenador y selecciona la placa y el puerto adecuados:**
   - Herramientas > Placa > Tu modelo de Arduino.
   - Herramientas > Puerto > Puerto COM correspondiente.

3. **Cargar el siguiente código de ejemplo al Arduino:**

```cpp
#include <Servo.h>

const int emgPin = A0;  // Pin de señal del módulo EMG
Servo servos[5];        // Arreglo de servos
int servoPins[5] = {3, 5, 6, 9, 10};  // Pines de control para los servos

void setup() {
  Serial.begin(9600);   // Inicializa la comunicación serial
  for (int i = 0; i < 5; i++) {
    servos[i].attach(servoPins[i]);  // Asigna los pines a los servos
    servos[i].write(90);             // Inicializa los servos en posición neutral
  }
}

void loop() {
  int emgValue = analogRead(emgPin);  // Lee el valor del módulo EMG
  Serial.println(emgValue);           // Imprime el valor en el Monitor Serial

  // Mapear el valor EMG a un ángulo de servo (0-180)
  int angle = map(emgValue, 0, 1023, 0, 180);

  for (int i = 0; i < 5; i++) {
    servos[i].write(angle);  // Ajusta la posición de cada servo según el valor EMG
  }

  delay(50);  // Pequeño retardo para suavizar el movimiento
}
```

## Herramientas de Depuración y Visualización

- **Monitor Serial del Arduino IDE:** Utilizado para visualizar las lecturas de las señales EMG.
- **Software de Visualización (Opcional):** Herramientas como MATLAB o Python para análisis detallado de las señales.
