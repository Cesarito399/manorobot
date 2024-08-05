# Cómo Utilizar el Proyecto de Prótesis de Mano Robótica Controlada por Señales EMG

## Preparativos Iniciales

1. **Montaje Completo:**
   - Asegúrate de que todos los componentes de hardware estén correctamente conectados, incluyendo el módulo EMG, los servomotores y el microcontrolador Arduino.

2. **Encendido del Sistema:**
   - Conecta las baterías de 9V y verifica que las conexiones sean firmes. Asegúrate de que el Arduino y los servomotores reciban alimentación.

3. **Configuración del Sensor EMG:**
   - Coloca los electrodos del módulo EMG sobre el músculo que deseas monitorizar. Asegúrate de que estén bien adheridos para obtener lecturas precisas.

## Operación Básica

1. **Iniciar el Arduino:**
   - Conecta el Arduino al ordenador y carga el código de control, asegurándote de que el Monitor Serial del Arduino IDE esté abierto.

2. **Monitorización de Señales:**
   - Observa las lecturas de las señales EMG en el Monitor Serial. Deberías ver valores que cambian al mover el músculo.

3. **Control de la Prótesis:**
   - A medida que cambias la tensión muscular, las lecturas del módulo EMG deberían variar. Estos cambios son interpretados por el Arduino y se traducen en movimientos de los servomotores.
   - La prótesis debería moverse de acuerdo con la intensidad de las señales EMG: un valor más alto resultará en un mayor movimiento de los servos.

## Iniciar una Sesión de Captura de Datos

1. **Captura de Datos:**
   - Utiliza el Monitor Serial para registrar los valores de las señales EMG a lo largo del tiempo.
   - Si deseas capturar datos para análisis posterior, puedes copiar estos valores desde el Monitor Serial a un archivo de texto o utilizar software adicional para grabar los datos.

2. **Análisis de Datos (Opcional):**
   - Puedes utilizar software como MATLAB, Python, o Excel para graficar y analizar los datos EMG capturados. Esto te permitirá observar patrones en la actividad muscular y ajustar la configuración del sistema.

## Interpretación de Resultados

1. **Interpretación de Señales:**
   - Los valores de las señales EMG representan la actividad eléctrica del músculo. Un aumento en el valor indica una mayor contracción muscular.

2. **Ajuste de Sensibilidad:**
   - Si los movimientos de la prótesis no son los esperados, considera ajustar la sensibilidad del módulo EMG. Esto puede incluir modificar la ganancia del sensor o ajustar el mapeo de las señales EMG a los ángulos de los servos en el código.

3. **Detección de Anomalías:**
   - Si observas lecturas anómalas o inconsistentes, verifica las conexiones eléctricas, la colocación de los electrodos y la calibración del sensor EMG.

## Comandos y Ejemplos

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
```