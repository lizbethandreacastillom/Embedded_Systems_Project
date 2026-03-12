#include <WiFi.h>
#include <ESPAsyncWebServer.h>

// Configuración de la Red (US-01)
const char* ssid = "SecureAccess_ESP32";
const char* password = "password123"; // Requisito de ciberseguridad

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  // Iniciando el Punto de Acceso
  WiFi.softAP(ssid, password);

  Serial.println("Punto de Acceso Iniciado");
  Serial.print("IP para el QR: ");
  Serial.println(WiFi.softAPIP());

  // Ruta principal para el celular del usuario
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", "<h1>Sistema de Acceso Seguro</h1><p>Escaneo exitoso. Ingrese su PIN.</p>");
  });

  server.begin();
}

void loop() {
  // Servidor asíncrono: no requiere lógica aquí
}
