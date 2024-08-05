# Prótesis de Mano Robótica Controlada por Señales EMG

## Descripción del Proyecto

Este proyecto consiste en el desarrollo de una prótesis de mano robótica controlada por señales mioeléctricas. Utilizando un microcontrolador Arduino, la prótesis emplea un módulo EMG para captar las señales eléctricas generadas por los músculos del usuario y convertirlas en movimiento a través de cinco microservomotores. El objetivo es proporcionar una solución accesible y eficaz para personas que requieren prótesis de mano, explorando aplicaciones en el campo de las interfaces electromecánicas.

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

## Limitaciones y Mejoras Futuras

- **Limitaciones:** La precisión del control de los servos depende de la calidad de las señales EMG capturadas. Es importante ajustar la ganancia y realizar pruebas exhaustivas.
- **Mejoras futuras:** Implementar algoritmos de procesamiento de señales más avanzados para mejorar la interpretación y respuesta a las señales EMG.

## Contribuciones

Si deseas contribuir a este proyecto, por favor envía un pull request o contacta al autor para más información.

Para utilizar el proyecto de prótesis de mano robótica controlada por señales EMG, sigue los pasos detallados a continuación. Estos pasos incluyen cómo operar el dispositivo, iniciar una sesión de captura de datos, e interpretar los resultados obtenidos.


## Cómo Operar el Dispositivo

### Preparativos Iniciales

1. **Montaje Completo:**
   - Asegúrate de que todos los componentes de hardware estén correctamente conectados, incluyendo el módulo EMG, los servomotores, y el microcontrolador Arduino.

2. **Encendido del Sistema:**
   - Conecta las baterías de 9V y verifica que las conexiones sean firmes. Asegúrate de que el Arduino y los servomotores reciban alimentación.

3. **Configuración del Sensor EMG:**
   - Coloca los electrodos del módulo EMG sobre el músculo que deseas monitorizar. Asegúrate de que estén bien adheridos para obtener lecturas precisas.

### Operación Básica

1. **Iniciar el Arduino:**
   - Conecta el Arduino al ordenador y carga el código de control, asegurándote de que el Monitor Serial del Arduino IDE esté abierto.

2. **Monitorización de Señales:**
   - Observa las lecturas de las señales EMG en el Monitor Serial. Deberías ver valores que cambian al mover el músculo.

3. **Control de la Prótesis:**
   - A medida que cambias la tensión muscular, las lecturas del módulo EMG deberían variar. Estos cambios son interpretados por el Arduino y se traducen en movimientos de los servomotores.
   - La prótesis debería moverse de acuerdo con la intensidad de las señales EMG: un valor más alto resultará en un mayor movimiento de los servos.

### Iniciar una Sesión de Captura de Datos

1. **Captura de Datos:**
   - Utiliza el Monitor Serial para registrar los valores de las señales EMG a lo largo del tiempo.
   - Si deseas capturar datos para análisis posterior, puedes copiar estos valores desde el Monitor Serial a un archivo de texto o utilizar software adicional para grabar los datos.

2. **Análisis de Datos (Opcional):**
   - Puedes utilizar software como MATLAB, Python, o Excel para graficar y analizar los datos EMG capturados. Esto te permitirá observar patrones en la actividad muscular y ajustar la configuración del sistema.

### Interpretación de Resultados

1. **Interpretación de Señales:**
   - Los valores de las señales EMG representan la actividad eléctrica del músculo. Un aumento en el valor indica una mayor contracción muscular.

2. **Ajuste de Sensibilidad:**
   - Si los movimientos de la prótesis no son los esperados, considera ajustar la sensibilidad del módulo EMG. Esto puede incluir modificar la ganancia del sensor o ajustar el mapeo de las señales EMG a los ángulos de los servos en el código.

3. **Detección de Anomalías:**
   - Si observas lecturas anómalas o inconsistentes, verifica las conexiones eléctricas, la colocación de los electrodos, y la calibración del sensor EMG.

### Comandos y Ejemplos

- **Inicio de Sesión:**
  - Enciende el sistema y carga el código al Arduino.
  - Abre el Monitor Serial para observar las lecturas en tiempo real.

- **Comandos en el Código:**
  - El código mapea automáticamente las señales EMG a los ángulos de los servos. Si deseas cambiar el comportamiento, modifica la función `map()` en el código de Arduino.

```cpp
// Ejemplo de mapeo de señal EMG a ángulo de servo
int angle = map(emgValue, 0, 1023, 0, 180);
```

- **Ajuste de Configuración:**
  - Modifica los umbrales y rangos en el código según sea necesario para lograr el comportamiento deseado.



## Limitaciones Actuales del Sistema

1. **Precisión de las Señales EMG:**
   - **Ruido en las Lecturas:** Las señales EMG son susceptibles a ruido y artefactos, lo que puede afectar la precisión del control de los servomotores.
   - **Colocación de Electrodos:** La precisión de las señales depende en gran medida de la colocación correcta de los electrodos en la piel. Una mala colocación puede llevar a lecturas inconsistentes.

2. **Limitaciones del Hardware:**
   - **Capacidad de Carga de los Servomotores:** Los microservos utilizados tienen una capacidad de carga limitada, lo que puede ser insuficiente para aplicaciones que requieren fuerza significativa.
   - **Duración de la Batería:** Las baterías de 9V pueden agotarse rápidamente dependiendo de la carga y el uso continuo del sistema.

3. **Complejidad del Procesamiento de Señales:**
   - **Filtro de Señales:** Implementar un filtrado adecuado para eliminar el ruido sin perder información importante es un desafío técnico.
   - **Interpretación de Señales:** La interpretación precisa de las señales EMG para movimientos complejos requiere algoritmos avanzados que no se han implementado en este proyecto básico.

## Desafíos Conocidos

1. **Calibración del Sistema:**
   - La calibración inicial puede ser complicada, ya que requiere ajustes precisos en la ganancia del sensor EMG y el mapeo de señales a movimientos.
   - **Variabilidad entre Usuarios:** Las señales EMG varían entre diferentes usuarios debido a la biología única de cada individuo, lo que requiere ajustes personalizados.

2. **Interferencia Electromagnética:**
   - El sistema puede ser susceptible a interferencias electromagnéticas de otros dispositivos electrónicos cercanos, afectando la precisión de las lecturas.

3. **Coste y Accesibilidad:**
   - El coste de los componentes, especialmente el sensor EMG y servomotores de calidad, puede ser prohibitivo para algunos usuarios.

## Planes Futuros y Mejoras Potenciales

1. **Implementación de Algoritmos Avanzados:**
   - Desarrollar e integrar algoritmos avanzados de procesamiento de señales para mejorar la interpretación y respuesta a las señales EMG.
   - Implementar técnicas de aprendizaje automático para personalizar el comportamiento de la prótesis a cada usuario.

2. **Mejora de la Interfaz de Usuario:**
   - Desarrollar una interfaz gráfica de usuario para facilitar la calibración y ajuste del sistema.
   - Proporcionar retroalimentación visual o táctil al usuario para mejorar la interacción con la prótesis.

3. **Optimización del Consumo de Energía:**
   - Investigar opciones de baterías más eficientes o fuentes de energía alternativas para prolongar la duración de la batería.
   - Mejorar la eficiencia energética del sistema mediante la optimización del código y el hardware.

4. **Expansión de Funcionalidades:**
   - Agregar sensores adicionales, como sensores de presión o táctiles, para proporcionar más información al sistema y mejorar el control de la prótesis.
   - Explorar la integración de comunicación inalámbrica para permitir el control remoto y la telemetría.

5. **Pruebas y Validación:**
   - Realizar pruebas extensivas con usuarios reales para recopilar datos y mejorar el diseño del sistema.
   - Colaborar con profesionales de la salud para asegurar que la prótesis cumpla con estándares clínicos y necesidades del usuario.

