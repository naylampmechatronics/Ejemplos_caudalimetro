# Ejemplos_caudalimetro
Códigos de ejemplo para sensores de caudal YF-S201, YF-DN50, FS300A, FS400A o similares

![Sensor de flujo de agua](https://naylampmechatronics.com/300-large_default/sensor-de-flujo-de-agua-12-yf-s201.jpg)

Información detallada de los ejemplos en: [Tutorial sensor de flujo de agua](https://naylampmechatronics.com/blog/47_tutorial-sensor-de-flujo-de-agua.html)

## Contenido
* **Flujo:** Programa para realizar mediciones de caudal
* **Volumen:** Programa para realizar mediciones de volumen y caudal
* **Pulsos:** Muestran la cantidad de los pulsos leídos del sensor flujo

## Requerimientos
 **Software**
  * IDE Arduino
  
 **Hardware**
  * [Arduino Uno](https://naylampmechatronics.com/arduino-tarjetas/8-arduino-uno-r3.html) (o cualquier modelo)
  * Sensor de flujo ( [YF-S201](https://naylampmechatronics.com/sensores-liquido/108-sensor-de-flujo-de-agua-12-yf-s201.html),  [FS300A](https://naylampmechatronics.com/sensores-liquido/156-sensor-de-flujo-de-agua-34-fs300a.html) o similar)
  
## Conexiones
  
  Sensor Flujo  | Arduino
  --------------|---------
  VCC (Cable Rojo)    | 5V  
  GND (Cable Negro)   | GND 
  OUT (Cable Amarillo)| D2   

  El pin asignado es un pin de interrupción externa, si desea cambiar puede usar otro pin siempre que tenga interrupción.

## Licencia
Los ejemplos son Open Source, desarrollados por el equipo de Naylamp Mechatronics bajo [licencia MIT](LICENSE)
 
## Links 
 * [Tutorial sensor de flujo de agua](https://naylampmechatronics.com/blog/47_tutorial-sensor-de-flujo-de-agua.html)
 * [Sensores de Líquido](https://naylampmechatronics.com/40-sensores-liquido) 
