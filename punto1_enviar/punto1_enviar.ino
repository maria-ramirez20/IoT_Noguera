#include "DHT.h"
#define DHTPIN 2  
#define DHTTYPE DHT22   // DHT 11 

DHT dht(DHTPIN, DHTTYPE);

// definimos variables 

int tem = 0;
int hum = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  lectura_sensores();
  delay(100);
  //enviar_datos1();
  //delay(1000);
  enviar_datos2();
  delay(12000);
}

void lectura_sensores(){
  
  hum = dht.readHumidity();
  tem = dht.readTemperature();

  /*if (isnan(hum) || isnan(tem)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }*/

  Serial.print(F("Humedad: "));
  Serial.print(hum);
  Serial.print(F("%  Temperatura: "));
  Serial.print(tem);
  Serial.println(F("°C "));

}

void enviar_datos1(){      

  Serial.write(0X7E); // cabecera 

  Serial.write(0X00); // tamaño de la trama
  Serial.write(0X0F);

  Serial.write(0X10);   // tipo de trama 
  Serial.write(0X01);
  
  Serial.write(0X00);// direccion mac
  Serial.write(0X00);
  Serial.write(0X00);
  Serial.write(0X00);
  Serial.write(0X00);
  Serial.write(0X00);
  Serial.write(0XFF);
  Serial.write(0XFE);
  
  Serial.write(0XFF);
  Serial.write(0XFE);
  Serial.write(0X00);
  Serial.write(0X00);
  
  Serial.write(tem);
  
  long suma = (0X10)+(0X01)+(0XFF)+(0XFE)+(0XFF)+(0XFE)+ tem;
  Serial.write(0XFF-(suma & 0XFF));

}


void enviar_datos2(){      


  Serial.write(0X7E); // cabecera 

  Serial.write(0X00); // tamaño de la trama
  Serial.write(0X10);

  Serial.write(0X10);   // tipo de trama 
  Serial.write(0X01);
  
  Serial.write(0X00);// direccion mac
  Serial.write(0X00);
  Serial.write(0X00);
  Serial.write(0X00);
  Serial.write(0X00);
  Serial.write(0X00);
  Serial.write(0XFF);
  Serial.write(0XFE);
  
  Serial.write(0XFF);
  Serial.write(0XFE);
  Serial.write(0X00);
  Serial.write(0X00);
  
  Serial.write(tem);
  Serial.write(hum);
  
  long suma = (0X10)+(0X01)+(0XFF)+(0XFE)+(0XFF)+(0XFE)+ tem + hum;
  Serial.write(0XFF-(suma & 0XFF));

}
