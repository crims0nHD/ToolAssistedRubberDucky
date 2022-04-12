// Software serial stuff
#include <SoftwareSerial.h>
#define PIN_STX 7
#define PIN_SRX 8
SoftwareSerial s_obj = SoftwareSerial(PIN_SRX, PIN_STX);

// USB HID
#define HID_CUSTOM_LAYOUT
#define LAYOUT_GERMAN
#include <HID-Project.h>

void setup() {
    pinMode(PIN_SRX, INPUT);
    pinMode(PIN_STX, OUTPUT);

    s_obj.begin(9600);
    s_obj.listen();
}

void loop() {
  if(s_obj.available() > 0) {
    char data = s_obj.read();
    Keyboard.write(data);
  }
}
