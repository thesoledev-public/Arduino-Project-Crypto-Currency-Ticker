#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid_1 = "[SSID_1_NAME]";
const char* password_1 = "[PASSWORD]";

const char* ssid_2 = "[SSID_2_NAME]";
const char* password_2 = "[PASSWORD]";



#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`
#include "images.h"


SSD1306  display(0x3c, D3, D5);


#define DEMO_DURATION 3000
typedef void (*Demo)(void);

int demoMode = 0;
int counter = 1;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid_1, password_1);

 int ctr_try = 0;
  while (WiFi.status() != WL_CONNECTED) {
 
    delay(1000);
    Serial.println("Connecting..");
    ctr_try = ctr_try + 1;

    if(ctr_try > 3){
      break;
    }
  }

  if(ctr_try > 3){
  
    WiFi.begin(ssid_2, password_2);
    while (WiFi.status() != WL_CONNECTED) {
   
      delay(1000);
      Serial.println("Connecting..");
      ctr_try = ctr_try + 1;
  
  
    }
  }

  // Initialising the UI will init the display too.
  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);

}

// [+] JBG

void fetchIotaVal() {
  
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
     Serial.println("CONNECTED");
    HTTPClient http;  //Declare an object of class HTTPClient
 
    http.begin("http://eglobalmd.com/api_ticker/ticker.php?curr=MIOTA");  //Specify request destination
    int httpCode = http.GET();                                                                  //Send the request
 
    if (httpCode > 0) { //Check the returning code
 
      String payload = http.getString();   //Get the request response payload
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_10);      
      display.setFont(ArialMT_Plain_16);
      display.setFont(ArialMT_Plain_24);
      display.drawString(42.67, 0, "IOTA");
      display.setFont(ArialMT_Plain_16);
      display.drawString((payload.length() * 5.2), 26, payload);
 
    }
 
    http.end();   //Close connection
 
  }
 
}


void fetchBTCVal() {
  
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
     Serial.println("CONNECTED");
    HTTPClient http;  //Declare an object of class HTTPClient
 
    http.begin("http://eglobalmd.com/api_ticker/ticker.php?curr=BTC");  //Specify request destination
    int httpCode = http.GET();                                                                  //Send the request
 
    if (httpCode > 0) { //Check the returning code
 
      String payload = http.getString();   //Get the request response payload
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_24);
      display.drawString(42.67, 0, "BTC");
      display.setFont(ArialMT_Plain_16);
      display.drawString((payload.length() * 5.2), 26, payload);
 
    }
     http.end();   //Close connection
 
  }
 
}

void fetchADAVal() {
  
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
     Serial.println("CONNECTED");
    HTTPClient http;  //Declare an object of class HTTPClient
 
    http.begin("http://eglobalmd.com/api_ticker/ticker.php?curr=ADA");  //Specify request destination
    int httpCode = http.GET();                                                                  //Send the request
 
    if (httpCode > 0) { //Check the returning code
 
      String payload = http.getString();   //Get the request response payload
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_24);
      display.drawString(42.67, 0, "ADA");
      display.setFont(ArialMT_Plain_16);
      display.drawString((payload.length() * 5.2), 26, payload);
 
    }
     http.end();   //Close connection
 
  }
 
}

void fetchXRPVal() {
  
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
     Serial.println("CONNECTED");
    HTTPClient http;  //Declare an object of class HTTPClient
 
    http.begin("http://eglobalmd.com/api_ticker/ticker.php?curr=XRP");  //Specify request destination
    int httpCode = http.GET();                                                                  //Send the request
 
    if (httpCode > 0) { //Check the returning code
 
      String payload = http.getString();   //Get the request response payload
      display.setTextAlignment(TEXT_ALIGN_LEFT);
      display.setFont(ArialMT_Plain_24);
      display.drawString(42.67, 0, "XRP");
      display.setFont(ArialMT_Plain_16);
      display.drawString((payload.length() * 5.2), 26, payload);
 
    }
     http.end();   //Close connection
 
  }
 
}
// [-] JBG


void drawFontFaceDemo() {
    // Font Demo1
    // create more fonts at http://oleddisplay.squix.ch/
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Hello world");
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 10, "Hello world");
    display.setFont(ArialMT_Plain_24);
    display.drawString(0, 26, "Hello world");
}

void drawTextFlowDemo() {
    display.setFont(ArialMT_Plain_10);
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawStringMaxWidth(0, 0, 128,
      "Lorem ipsum\n dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore." );
}

void drawTextAlignmentDemo() {
    // Text alignment demo
  display.setFont(ArialMT_Plain_10);

  // The coordinates define the left starting point of the text
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(0, 10, "Left aligned (0,10)");

  // The coordinates define the center of the text
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(64, 22, "Center aligned (64,22)");

  // The coordinates define the right end of the text
  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(128, 33, "Right aligned (128,33)");
}

void drawRectDemo() {
      // Draw a pixel at given position
    for (int i = 0; i < 10; i++) {
      display.setPixel(i, i);
      display.setPixel(10 - i, i);
    }
    display.drawRect(12, 12, 20, 20);

    // Fill the rectangle
    display.fillRect(14, 14, 17, 17);

    // Draw a line horizontally
    display.drawHorizontalLine(0, 40, 20);

    // Draw a line horizontally
    display.drawVerticalLine(40, 0, 20);
}

void drawCircleDemo() {
  for (int i=1; i < 8; i++) {
    display.setColor(WHITE);
    display.drawCircle(32, 32, i*3);
    if (i % 2 == 0) {
      display.setColor(BLACK);
    }
    display.fillCircle(96, 32, 32 - i* 3);
  }
}

void drawProgressBarDemo() {
  int progress = (counter / 5) % 100;
  // draw the progress bar
  display.drawProgressBar(0, 32, 120, 10, progress);

  // draw the percentage as String
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(64, 15, String(progress) + "%");
}

void drawImageDemo() {
    // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
    // on how to create xbm files
    display.drawXbm(34, 14, WiFi_Logo_width, WiFi_Logo_height, WiFi_Logo_bits);
}

//Demo demos[] = {drawProgressBarDemo, drawImageDemo,fetchIotaVal};
Demo demos[] = {fetchBTCVal,fetchIotaVal,fetchADAVal,fetchXRPVal};
int demoLength = (sizeof(demos) / sizeof(Demo));
long timeSinceLastModeSwitch = 0;

void loop() {
  
  // clear the display
  display.clear();
  // draw the current demo method
  demos[demoMode]();

  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(10, 128, String(millis()));
  // write the buffer to the display
  display.display();

  if (millis() - timeSinceLastModeSwitch > DEMO_DURATION) {
    demoMode = (demoMode + 1)  % demoLength;
    timeSinceLastModeSwitch = millis();
  }
  counter++;
  delay(10);
}
