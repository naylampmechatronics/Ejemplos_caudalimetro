/****************************************************************************************
 Flujo

  Se realizan mediciones de caudal usando un sensores de flujo YF-S201, YF-DN50, FS300A, FS400A o similar
  Modificar el factor_conversion dependiendo del modelo de sensor
 
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
volatile int NumPulsos; //variable para la cantidad de pulsos recibidos
int PinSensor = 2;    //Sensor conectado en el pin 2
float factor_conversion=7.5; //para convertir de frecuencia a caudal

//---Función que se ejecuta en interrupción---------------
void ContarPulsos ()
{ 
  NumPulsos++;  //incrementamos la variable de pulsos
} 

//---Función para obtener frecuencia de los pulsos--------
int ObtenerFrecuencia() 
{
  int frecuencia;
  NumPulsos = 0;   //Ponemos a 0 el número de pulsos
  interrupts();    //Habilitamos las interrupciones
  delay(1000);   //muestra de 1 segundo
  noInterrupts(); //Deshabilitamos las interrupciones
  frecuencia=NumPulsos; //Hz(pulsos por segundo)
  return frecuencia;
}

void setup()
{ 
  Serial.begin(9600); 
  pinMode(PinSensor, INPUT); 
  attachInterrupt(0,ContarPulsos,RISING); //(Interrupcion 0(Pin2),funcion,Flanco de subida)
} 

void loop ()    
{
  float frecuencia=ObtenerFrecuencia(); //obtenemos la Frecuencia de los pulsos en Hz
  float caudal_L_m=frecuencia/factor_conversion; //calculamos el caudal en L/m
  float caudal_L_h=caudal_L_m*60; //calculamos el caudal en L/h

  //-----Enviamos por el puerto serie---------------
  Serial.print ("FrecuenciaPulsos: "); 
  Serial.print (frecuencia,0); 
  Serial.print ("Hz\tCaudal: "); 
  Serial.print (caudal_L_m,3); 
  Serial.print (" L/m  "); 
   Serial.print (caudal_L_h,3); 
  Serial.println (" L/h"); 
}
