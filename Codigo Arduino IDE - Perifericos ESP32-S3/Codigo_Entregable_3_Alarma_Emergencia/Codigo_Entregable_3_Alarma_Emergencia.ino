#define pinAlarma 2 
#define pinSwitch 4

int estadoPalanca; 
int estadoPalancaAnterior;
bool sonandoAlarma = false;
bool estadoSonidoAnterior = false;
bool alarmaActivada = false;
unsigned long tiempoAnterior = 0;
unsigned long tiempoActual = 0;

void setup() {
  pinMode(pinAlarma, OUTPUT);
  pinMode(pinSwitch, INPUT_PULLUP); //cuando baje la palanca se pondra en LOW el pinSwitch, HIGH si esta conectada
  digitalWrite(pinAlarma, LOW);
  
  // Inicia la comunicación serial a 115200 baudios
  Serial.begin(115200);

  estadoPalanca = digitalRead(pinSwitch);
  estadoPalancaAnterior = estadoPalanca;
}

void loop() {

  estadoPalanca = digitalRead(pinSwitch); //HIGH si la alarma esta conectada y LOW si esta desconectada

  if(estadoPalanca != estadoPalancaAnterior){ //solo revisa el estado nuevamente si el estado ha cambiado para evitar saturar la memoria RAM con 38912840918904 millones de mensajes de conectada
    if(estadoPalanca == HIGH){
    Serial.println("Conectada");
    }
    else{
      Serial.println("Desconectada");
    }
  }
  estadoPalancaAnterior = estadoPalanca;
  
  // Verifica si Visual Studio ha enviado la trama
  if (Serial.available() > 0) {
    
    // Lee toda la cadena hasta el salto de línea (\n)
    String comando = Serial.readStringUntil('\n'); 
    comando.trim(); // Limpia espacios o caracteres nulos
    
    if (comando == "1") {
      alarmaActivada = true;
    } 
    else if (comando == "0") {
      alarmaActivada = false; 
    }
    else if(comando == "2"){ //para revisar apenas abre la pantalla el estado inicial
      if(estadoPalanca == HIGH) {
        Serial.println("Conectada");
      } 
      else {
        Serial.println("Desconectada");
      }

      if(alarmaActivada && estadoPalanca == HIGH) {
        Serial.println("Sonando");
      } 
      else {
        Serial.println("Silenciada");
      }
    }
  }
  
  tiempoActual = millis();
  if(alarmaActivada && estadoPalanca == HIGH){
    
    if(tiempoActual - tiempoAnterior >= 100){ //si ya pasaron 100 ms actualiza el estado de sonando alarma
      tiempoAnterior = tiempoActual;

      sonandoAlarma = !sonandoAlarma;
      
      if(sonandoAlarma){ //si es true sonamos la alarma con HIGH
        digitalWrite(pinAlarma, HIGH);
      }
      else{
        digitalWrite(pinAlarma, LOW);
      }

      if(estadoSonidoAnterior == false){ //cambiamos el mensaje a leer solo si cambia el estado de sonido
        Serial.println("Sonando");
        estadoSonidoAnterior = true;
      }

    }
  }
  
  else{ //si de desactiva la alarma o se desconecta apagamos todo 
    sonandoAlarma = false;
    digitalWrite(pinAlarma, LOW);
    if(estadoSonidoAnterior == true) {
      Serial.println("Silenciada");
      estadoSonidoAnterior = false;
    }
  }
  
/*
//Codigo de prueba

  digitalWrite(pinAlarma, HIGH);
  Serial.println("Prendido");
  delay(500);
  digitalWrite(pinAlarma, LOW);
  Serial.println("Apagado");
  delay(500);
*/
}
