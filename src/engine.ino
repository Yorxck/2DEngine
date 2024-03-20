#include <Adafruit_SSD1306.h>
#include <Wire.h>
//#include "engine.h"


Adafruit_SSD1306 display(128, 64, &Wire, -1);

//Rectangle rect1(Vector2(20, 20), Vector2::zero, Vector2(2, 2));
//Rectangle rect2(Vector2(21, 21), Vector2::zero, Vector2(2, 2));

void setup() {
  Serial.begin(115200);

  if (!display.begin()) {
    Serial.println("SSD1306 allocation failed");
    for (;;)
      ;
  }
}

void loop() {
  Serial.println("");
  display.clearDisplay();
  //display.drawRect(rect1.GetPosition()->X, rect1.GetPosition()->Y - rect1.size.Y, rect1.size.X, rect1.size.Y, SSD1306_WHITE);
  display.drawRect(20, 20, 2, 2, SSD1306_WHITE);

  display.display();
}
