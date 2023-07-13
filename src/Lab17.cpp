/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#line 1 "/Users/ashleylibasci/IoTFolderLabs/Lab17/src/Lab17.ino"
#include "oled-wing-adafruit.h"
#include "Particle.h"
#include "MQTT.h"

void setup();
void loop();
#line 5 "/Users/ashleylibasci/IoTFolderLabs/Lab17/src/Lab17.ino"
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;

void callback(char *topic, byte *payload, unsigned int length);

MQTT client("lab.thewcl.com", 1883, callback);

void setup()
{
  Serial.begin(9600);

  display.setup();
  display.clearDisplay();
  display.display();
}

void loop()
{
  display.loop();

  if (client.isConnected())
  {
    client.loop();
  }
  else
  {
    client.connect(System.deviceID());
    client.subscribe("Lab17");
    client.publish("Lab17", "Lab17Connected");
  }
}