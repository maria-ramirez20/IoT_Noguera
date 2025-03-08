### Ejercicio 1:

##### A)

Por medio de la ESP32 construya un algoritmo para lectura de 2 sensores (DHT22 o DHT11), otro de su preferencia (LM35, BME680, etc). En total se requieren como mínimo de tres variables de lectura.

##### B) 
Ahora genere la trama API para enviar estas variables al nodo coordinador con una frecuencia de 10 segundos.

##### C)
Verifique en el nodo coordinador la información de llegada por medio del software XCTU, estudie cada una de las tramas e identifique los datos de las variables de los sensores.

##### D)
Ahora integre otro sistema embebido de su preferencia y muestre por el monitor serial la dirección MAC del origen de la información, al igual que el valor de cada uno de los variables. Este sistema embebido se integra con el nodo coordinador. 

## Carpetas

```
└── 📁IoT_Noguera
    └── 📁punto1_enviar
        └── punto1_enviar.ino
    └── 📁Punto1_recibir
        └── punto1_recibir.ino
    └── LICENSE
    └── README.md
```