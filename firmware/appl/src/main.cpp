#include <WiFi.h>
#include <Servo.h>

// Configuración de red (Access Point personalizada)
const char* ssid = "Cerradura Inteligente";
const char* password = "jun03oct07";
WiFiServer server(80);

Servo miServo;
const int pinVerde = 2;
const int pinRojo = 5;    // CAMBIADO: Ahora es el pin 5
const int pinServo = 18;
String pinCorrecto = "0307"; // CAMBIADO: Nuevo PIN de acceso

void setup() {
  Serial.begin(115200);
  
  // Configuración de Hardware
  pinMode(pinVerde, OUTPUT);
  pinMode(pinRojo, OUTPUT);
  miServo.attach(pinServo);
  miServo.write(0); // Cerrado por defecto

  // Iniciar el Punto de Acceso con los nuevos datos
  Serial.print("Iniciando red: "); Serial.println(ssid);
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  server.begin();
  
  Serial.println("¡Sistema en línea!");
  Serial.print("IP del servidor: "); Serial.println(IP);
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (c == '\n') {
          if (currentLine.length() == 0) {
            // Respuesta HTML
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.println("<html><head><meta charset='UTF-8'></head><body>");
            client.println("<h2>Cerradura Inteligente - Panel de Acceso</h2>");
            client.println("<form action='/L'>Ingrese PIN: <input type='password' name='p'>");
            client.println("<input type='submit' value='Desbloquear'></form></body></html>");
            client.println();
            break;
          } else { currentLine = ""; }
        } else if (c != '\r') { currentLine += c; }

        // Lógica de validación con el nuevo PIN 0307
        if (currentLine.endsWith("GET /L?p=" + pinCorrecto)) {
          Serial.println("Acceso Concedido");
          digitalWrite(pinVerde, HIGH);
          miServo.write(90); // Abrir
          delay(3000);       // Esperar 3 segundos
          miServo.write(0);  // Cerrar
          digitalWrite(pinVerde, LOW);
        } else if (currentLine.indexOf("GET /L?p=") != -1 && !currentLine.endsWith(pinCorrecto)) {
          Serial.println("Acceso Denegado");
          digitalWrite(pinRojo, HIGH);
          delay(1500);
          digitalWrite(pinRojo, LOW);
        }
      }
    }
    client.stop();
  }
}