#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int buzzerPin = 3;
int touchPin = 4;
int gndPin = 5;
int g2 = 2;
int h = 1;


void setup() {
  Serial.begin(115200);

  pinMode(buzzerPin, OUTPUT);
  pinMode(touchPin, INPUT);
  pinMode(gndPin, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(h, OUTPUT);
  digitalWrite(gndPin, LOW); // GPIO5 acts as GND
digitalWrite(g2, LOW); 
digitalWrite(h, HIGH); 
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  drawNeutralFace(); // Start with neutral face
}

void loop() {
  int touchState = digitalRead(touchPin);

  if (touchState == HIGH) {
    digitalWrite(buzzerPin, HIGH); // buzzer ON
    drawSmilingFace();             // smiling face
  } else {
    digitalWrite(buzzerPin, LOW);  // buzzer OFF
    drawNeutralFace();             // neutral face
  }
}

// Neutral face
void drawNeutralFace() {
  display.clearDisplay();
  display.drawRect(20, 10, 88, 44, SSD1306_WHITE); // head
  display.fillCircle(40, 30, 6, SSD1306_WHITE);    // left eye
  display.fillCircle(88, 30, 6, SSD1306_WHITE);    // right eye
  display.drawLine(45, 45, 83, 45, SSD1306_WHITE); // straight mouth
  display.display();
}

// Smiling face
void drawSmilingFace() {
  display.clearDisplay();
  display.drawRect(20, 10, 88, 44, SSD1306_WHITE); // head
  display.fillCircle(40, 30, 6, SSD1306_WHITE);    // left eye
  display.fillCircle(88, 30, 6, SSD1306_WHITE);    // right eye
  // Smile using lines
  display.drawLine(45, 45, 55, 50, SSD1306_WHITE);
  display.drawLine(55, 50, 73, 50, SSD1306_WHITE);
  display.drawLine(73, 50, 83, 45, SSD1306_WHITE);
  display.display();
}

