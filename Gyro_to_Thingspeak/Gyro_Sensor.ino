#include <WiFi.h>

const char *ssid = "SSID"; // Replace with your WiFi credentials
const char *password = "Password";
const char *thingSpeakAPIKey = "chanel key";

int detectorPin = 2;  // obstacle avoidance sensor interface
int val;              // variable to store result


void setup()
{
  pinMode(detectorPin, INPUT);  // Define obstacle avoidance sensor as input interface
  Serial.begin(115200);
  // [uncomment and remove jumper on module to use enable pin (EN)]
  //pinMode(enablePin, OUTPUT);
  //digitalWrite(enablePin, HIGH);  // Enable sensor
  WiFi.begin(ssid, password);
}

void loop()
{
  val = digitalRead(detectorPin); // Read value from sensor
  Serial.println(val);
  delay (4000);
  // Send data to ThingSpeak
  sendToThingSpeak(val);
  delay(5000); // Delay for 5 seconds
}
void sendToThingSpeak(float val) {
WiFiClient client;
const char *server = "api.thingspeak.com";
String data = "GET /update?api_key=" + String(thingSpeakAPIKey);
data += "&field1=" + String(val);
data += "\r\n";
if (client.connect(server, 80)) {
client.print(data);
client.stop();
Serial.println("Data sent to ThingSpeak!");
} else {

Serial.println("Failed to connect to ThingSpeak server!");
}
}