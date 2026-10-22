const int pinAlarma = 2; // Pin del LED integrado (cambiar luego al pin conectado a la resistencia del transistor)

void setup() {
  pinMode(pinAlarma, OUTPUT);
  digitalWrite(pinAlarma, LOW);
  
  // Inicia la comunicación serial a 115200 baudios (estándar para ESP32)
  Serial.begin(115200);
}

void loop() {
  // Verifica si Visual Studio ha enviado algún byte
  if (Serial.available() > 0) {
    char comando = Serial.read(); // Lee un solo caracter
    
    if (comando == '1') {
      digitalWrite(pinAlarma, HIGH); // Activa el LED / Dispara el SCR
    } 
    else if (comando == '0') {
      digitalWrite(pinAlarma, LOW);  // Apaga el LED / Corta el relé de rearme
    }
  }


//Codigo de prueba
/*
  digitalWrite(pinAlarma, HIGH);
  Serial.println("Prendido");
  delay(500);
  digitalWrite(pinAlarma, LOW);
  Serial.println("Apagado");
  delay(500);
*/
}
