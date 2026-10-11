int led = 18;
int trig = 13;
int eco = 12;
int DR = 14;
int DF = 27;
int IF = 26;
int IR = 33;
float duracion;
float distancia;


unsigned long tiempoAnterior = 0;
const long intervaloGiro = 1000;
bool girandoDerecha = true;

//----------------------------------//
void setup() {
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    pinMode(trig, OUTPUT);
    pinMode(eco, INPUT);
    pinMode(IF, OUTPUT);
    pinMode(DF, OUTPUT);
    pinMode(IR, OUTPUT);
    pinMode(DR, OUTPUT);

    //INICIO ANTES DEL CODIGO
    // EJEMPLO: Hacer que el robot vaya para atras por 2 segundos (2000 ms)  y despues va hacia un lado antes de empezar a buscar
        digitalWrite(DF, LOW); 
        digitalWrite(IF, LOW);
        digitalWrite(DR, HIGH);
        digitalWrite(IR, HIGH);
        delay(1000);

        digitalWrite(DF, LOW); 
        digitalWrite(IF, HIGH);
        digitalWrite(DR, LOW);
        digitalWrite(IR, LOW);
        delay(1000);

        digitalWrite(DF, LOW); 
        digitalWrite(IF, LOW);
        digitalWrite(DR, HIGH);
        digitalWrite(IR, HIGH);
        delay(1000);
        
        digitalWrite(DF, LOW); 
        digitalWrite(IF, LOW);
        digitalWrite(DR, LOW);
        digitalWrite(IR, LOW);
        Serial.println("SECUENCIA PREVIA FINALIZADA. COMIENZA EL BUCLE PRINCIPAL.");
}

//--------------------------------------------------------------//
void loop() {
    digitalWrite(trig, LOW);
    delayMicroseconds(2); 
    digitalWrite(trig, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trig, LOW);
    duracion = pulseIn(eco, HIGH);
    distancia = duracion / 58.2;

    unsigned long tiempoActual = millis(); // Obtener el tiempo actual

    if (distancia <= 35) {
        digitalWrite(DF, HIGH); 
        digitalWrite(IF, HIGH);
        digitalWrite(DR, LOW);
        digitalWrite(IR, LOW);
        Serial.println("ATACANDO");
        tiempoAnterior = tiempoActual;
    }
    else {
        if (tiempoActual - tiempoAnterior >= intervaloGiro) {
            tiempoAnterior = tiempoActual;
            girandoDerecha = !girandoDerecha;
            Serial.print("CAMBIO DE DIRECCIÓN: ");
            Serial.println(girandoDerecha ? "Derecha" : "Izquierda");
        }
        
        if (girandoDerecha) {
            digitalWrite(DF, HIGH);
            digitalWrite(IF, LOW);
            digitalWrite(DR, LOW);
            digitalWrite(IR, HIGH);
            Serial.println("BUSCANDO (Derecha)");
        } else {
            digitalWrite(DF, LOW);
            digitalWrite(IF, HIGH);
            digitalWrite(DR, HIGH);
            digitalWrite(IR, LOW);
            Serial.println("BUSCANDO (Izquierda)");
        }
    }
    
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");
    
    delay(100); 
}