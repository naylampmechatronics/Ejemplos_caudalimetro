/****************************************************************************************
 Pulsos

  Se muestran la cantidad de los pulsos leídos del sensor flujo
 
 Conexiones:
  -----------------------
  Sensor Flujo  -> Arduino
  -----------------------
  VCC (Rojo)    -> 5V  
  GND (Negro)   -> GND 
  OUT (Amarillo)-> D2   
  ---------------
  *El pin asignado es un pin de interrupción externa, si desea cambiar puede usar otro pin siempre que tenga interrupción.
 
 Última modificación el 04/09/2020
 
 Más información en:
   -https://naylampmechatronics.com/blog/47_tutorial-sensor-de-flujo-de-agua.html
   -https://github.com/naylampmechatronics/Ejemplos_caudalimetro
   
**************************************************************************************************/
volatile long NumPulsos; //variable para la cantidad de pulsos recibidos
int PinSensor = 2;    //Sensor conectado en el pin 2


//---Función que se ejecuta en interrupción---------------
void ContarPulsos ()
{ 
  NumPulsos++;  //incrementamos la variable de pulsos
} 

//---Función para obtener frecuencia de los pulsos--------

void setup()
{ 
  Serial.begin(9600); 
  pinMode(PinSensor, INPUT); 
  attachInterrupt(0,ContarPulsos,RISING);//(Interrupción 0(Pin2),función,Flanco de subida)
  interrupts();    //Habilitamos las interrupciones
} 

void loop ()    
{
  //-----Enviamos por el puerto serie---------------
  Serial.print ("Numero de Pulsos = "); 
  Serial.println (NumPulsos); 
  delay(100);
}
