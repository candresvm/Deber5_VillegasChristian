 
 int on=0;
 String dato;
 int giro;
 #include<Servo.h>
 Servo servo1;
 
void setup() {
   Serial.begin(9600);
   attachInterrupt(0,activacion,LOW);
   servo1.attach(3);
}

void loop() {
  delay(20);
  if(on==2){
      if(Serial.available()>0){
        dato=Serial.readString();
        giro=dato.toInt();
        servo1.write(giro);
   }
  }
}
void activacion(){
  switch(on){
      case 0:
        Serial.println("INICIO DE SISTEMA");
        on++;
      break;
      case 1:
        Serial.println("Ingrese un valor de 0 a 180");
        on++;
      break;
      case 2:
        Serial.println("Fin de sistema");
        on=0;
      break;
    }
}
