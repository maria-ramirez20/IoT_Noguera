int dato = 0;
int cont =0;
int dato1 = 0;
int dato2 = 0;
int temperatura = 0;
float voltaje = 0;
long lectura = 0;
String DireccionMAC;

void setup() {
  Serial.begin(9600);
}

void loop() {

  while(Serial.available()>0){

    dato = Serial.read();
    //Serial.print(dato,HEX);
    cont++;

    if(dato==126){
      cont =0;
    }

    if(cont >3 && cont <12){
      DireccionMAC = String(dato, HEX);
      Serial.print(DireccionMAC);
    }
    Serial.print(" ");

    if(cont == 15){
      Serial.print("Temperatura del DHT22: ");
      Serial.print(dato,DEC);
    }
    Serial.print(" ");

    if(cont == 16){
      Serial.print("Humedad del DHT22: ");
      Serial.print(dato,DEC);
      Serial.println("");
    }
    /*------------------------------sensor lm35-------------------------------*/
    Serial.print(" ");
    if (cont==21){
      dato2 =dato;
    }

    if (cont==22){
      dato1 =dato;

      lectura = dato2*256+dato1;
      voltaje = (lectura*1200)/(1223);
      temperatura = voltaje/10;
      Serial.print(temperatura);
    }
 
  }

}
