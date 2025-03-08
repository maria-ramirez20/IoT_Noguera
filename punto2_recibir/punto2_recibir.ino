int dato = 0;
int cont = 0;
int dato1 = 0;
int dato2 = 0;
int temperatura = 0;
float voltaje = 0;
long lectura = 0;
String direccionMACCompleta = "";
String direccionMACObjetivo = "0013A20040DA4447";  // MAC de referencia

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (Serial.available() > 0) {
    dato = Serial.read();
    cont++;

    // Reiniciar contador si detectamos el inicio del paquete (126 en decimal)
    if (dato == 126) {
      cont = 0;
      direccionMACCompleta = ""; // Reiniciar almacenamiento de MAC
    }

    // Acumular la dirección MAC (bytes del 4 al 11)
    if (cont > 3 && cont < 12) {
      if (dato < 16) {
        direccionMACCompleta += "0";  // Asegurar formato de dos caracteres
      }
      direccionMACCompleta += String(dato, HEX);
    }

    // Cuando se haya recibido la MAC completa, convertir a mayúsculas
    if (cont == 11) {
      direccionMACCompleta.toUpperCase();  // Asegurar que la comparación sea correcta
      Serial.print("\nMAC Recibida: ");
      Serial.println(direccionMACCompleta);
    }

    // Si la MAC coincide, mostrar datos del LM35
    if (direccionMACCompleta == direccionMACObjetivo) {
      if (cont == 19) {
        dato2 = dato;
      }
      if (cont == 20) {
        dato1 = dato;
        lectura = dato2 * 256 + dato1;
        voltaje = (lectura * 1200) / (1223);
        temperatura = voltaje / 10;
        Serial.print("Temperatura LM35: ");
        Serial.println(temperatura);
      }
    } 
    
    // Si la MAC es diferente, mostrar datos del DHT22
    else {
      if (cont == 15) {
        Serial.print("Temperatura DHT22: ");
        Serial.println(dato, DEC);
      }
      if (cont == 16) {
        Serial.print("Humedad DHT22: ");
        Serial.println(dato, DEC);
      }
    }
  }
}
