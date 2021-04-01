///////////////////////////////////////////////
// RobotDyn Keypad 4x4 Macro Script ver1.0  //
/********************************************
// Arduino Pro Micro
// 3-Wire Connection
// ~ Data Pin on A0
// ~ Power 5V on VCC
// ~ Ground on GND
//
// KeyPad Breakout for Pro Micro v1.0 by Robert Cole
***********************************/
// Created by Robert Cole

// KEY REFERENCE GUIDE
/*
KEY_LEFT_CTRL
KEY_LEFT_SHIFT
KEY_LEFT_ALT
KEY_LEFT_GUI
KEY_RIGHT_CTRL
KEY_RIGHT_SHIFT
KEY_RIGHT_ALT
KEY_RIGHT_GUI
KEY_UP_ARROW
KEY_DOWN_ARROW
KEY_LEFT_ARROW
KEY_RIGHT_ARROW
KEY_BACKSPACE
KEY_TAB
KEY_RETURN
KEY_ESC
KEY_INSERT
KEY_DELETE
KEY_PAGE_UP
KEY_PAGE_DOWN
KEY_HOME
KEY_END
KEY_CAPS_LOCK
KEY_F1
KEY_F2
KEY_F3
KEY_F4
KEY_F5
KEY_F6
KEY_F7
KEY_F8
KEY_F9
KEY_F10
KEY_F11
KEY_F12
KEY_F13
KEY_F14
KEY_F15
KEY_F16
KEY_F17
KEY_F18
KEY_F19
KEY_F20
KEY_F21
KEY_F22
KEY_F23
KEY_F24

*** CONSUMER.WRITE KEY LIST ***

MEDIA_FAST_FORWARD
MEDIA_REWIND
MEDIA_NEXT
MEDIA_PREVIOUS
MEDIA_STOP
MEDIA_PLAY_PAUSE

MEDIA_VOLUME_MUTE
MEDIA_VOLUME_UP
MEDIA_VOLUME_DOWN

CONSUMER_EMAIL_READER
CONSUMER_CALCULATOR
CONSUMER_EXPLORER

CONSUMER_BROWSER_HOME
CONSUMER_BROWSER_BACK
CONSUMER_BROWSER_FORWARD
CONSUMER_BROWSER_REFRESH
CONSUMER_BROWSER_BOOKMARKS

*/

// Include HID-Project by NicoHood - Keyboard Library
#include <HID-Project.h>

// Include Encorder Library
#include <Encoder.h>

// Analog Data Pin = Pin A0 or Pin 18 FOR RobotDyn 4x4 (3-wire) KEYPAD / AIN->OUT
const int buttonPin = A0;

// On Press Button Flash LED
const int flashLED = A2;

// LED MODE Indicator Pins
const int MODE1 = 15;
const int MODE2 = 14;
const int MODE3 = 16;
int  currentMode = 0;

// ENCODER SETUP
bool encoderOneEnable = true; // DEFAULT ENCODER on R_ENC1
bool encoderTwoEnable = true; // SECONDARY ENCODER on R_ENC2

// ENCODER 1 SETUP
const int buttonMute = 7; // MUTE BUTTON / Switch Pin

Encoder knobVol(8, 9);  // VOLUME KNOB

int stateVol = 0;
long volValue  = -999;

// ENCODER 2 SETUP
const int buttonMuteTWO = 4; // MUTE BUTTON / Switch Pin

Encoder knobVolTWO(19, 21);  // VOLUME KNOB / Second Encoder

int stateVolTWO = 0;
long volValueTWO  = -999; 

// Get KeyPaD Analog Value
int get_button(int val) {
 // Lets get the Current Mode to Decide Which Macro Layout to Use
 switch(currentMode){
 // DEFAULT LAYOUT
 
 // MODE 1 SETUP ******************************************
 case 0:
  // get analog input value
 if(val>1000){
    Consumer.write(CONSUMER_BROWSER_HOME);
    delay(200);
    return 1;
 }
 else if(val>900){
    Consumer.write(CONSUMER_BROWSER_BACK);
    delay(200);
    return 2;
 }
 else if(val>820){
    Consumer.write(CONSUMER_BROWSER_FORWARD);
    delay(200);
    Keyboard.releaseAll();
    return 3;
 }
 else if(val>750){
    Consumer.write(CONSUMER_BROWSER_REFRESH);
    delay(200);
    return 4;
 }
 else if(val>660){
    Consumer.write(CONSUMER_CALCULATOR);
    delay(200);
    return 5;
 }
 else if(val>620){
    Consumer.write(CONSUMER_EMAIL_READER);
    delay(200);
    return 6;
 }
 else if(val>585){
    Consumer.write(CONSUMER_EXPLORER);
    delay(200);
    return 7;
 }
 else if(val>540){
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press(KEY_LEFT_SHIFT); //Presses the CTRL key.
    Keyboard.press('o'); //Presses the F16 key.
    delay(200);
    Keyboard.releaseAll();
    return 8;
 }
 else if(val>500){
    Consumer.write(MEDIA_PREVIOUS);
    delay(200);
    return 9;
 }
 else if(val>475){
    Consumer.write(MEDIA_NEXT);
    delay(200);
    return 10;
 }
 else if(val>455){
    Consumer.write(MEDIA_PLAY_PAUSE);
    delay(200);
    return 11;
 }
 else if(val>425){
    Consumer.write(MEDIA_STOP);
    delay(200);
    return 12;
 }
 else if(val>370){
    // Switch Mode Button on 13
    // Add 1 to the Current Mode
    currentMode++;
    if (currentMode == 4) {
      // RESET to 0 when MAX. 
      currentMode = 0;
    }
    switch_Mode(currentMode);
    delay(200);
    Keyboard.releaseAll();
    return 13;
 }
 else if(val>300){
    // Change TAB View
    Keyboard.press(KEY_LEFT_ALT); //Presses the LEFT ALT key.
    Keyboard.press(KEY_TAB); //Presses the TAB key.
    Keyboard.release(KEY_TAB); // Release Single Keypress.
    Keyboard.press(KEY_TAB); //Presses the TAB key.
    delay(200);
    Keyboard.releaseAll();
    return 14;
 }
 else if(val>260){
    // COPY
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press('c'); //Presses the C key.
    delay(200);
    Keyboard.releaseAll();
    return 15;
 }
 else if(val>200){
    // PASTE
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press('v'); //Presses the C key.
    delay(200);
    Keyboard.releaseAll();
    return 16;
 }
 else {
    return 0;
 }
    break;

// MODE 2 SETUP ******************************************   
 case 1:
 // get analog input value
 if(val>1000){
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press(KEY_F13); //Presses the F13 key.
    delay(200);
    Keyboard.releaseAll();
    return 1;
 }
 else if(val>900){
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press(KEY_F14); //Presses the F14 key.
    delay(200);
    Keyboard.releaseAll();
    return 2;
 }
 else if(val>820){
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press(KEY_F15); //Presses the F15 key.
    delay(200);
    Keyboard.releaseAll();
    return 3;
 }
 else if(val>750){
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press(KEY_F16); //Presses the F16 key.
    delay(200);
    Keyboard.releaseAll();
    return 4;
 }
 else if(val>660){
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press(KEY_F17); //Presses the F17 key.
    delay(200);
    Keyboard.releaseAll();
    return 5;
 }
 else if(val>620){
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press(KEY_F18); //Presses the F18 key.
    delay(200);
    Keyboard.releaseAll();
    return 6;
 }
 else if(val>585){
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press(KEY_F19); //Presses the F19 key.
    delay(200);
    Keyboard.releaseAll();
    return 7;
 }
 else if(val>540){
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press(KEY_F20); //Presses the F20 key.
    delay(200);
    Keyboard.releaseAll();
    return 8;
 }
 else if(val>500){
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press(KEY_F21); //Presses the F21 key.
    delay(200);
    Keyboard.releaseAll();
    return 9;
 }
 else if(val>475){
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press(KEY_F22); //Presses the F22 key.
    delay(200);
    Keyboard.releaseAll();
    return 10;
 }
 else if(val>455){
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press(KEY_F23); //Presses the F23 key.
    delay(200);
    Keyboard.releaseAll();
    return 11;
 }
 else if(val>425){
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press(KEY_F24); //Presses the F24 key.
    delay(200);
    Keyboard.releaseAll();
    return 12;
 }
 else if(val>370){
    // Switch Mode Button on 13
    // Add 1 to the Current Mode
    currentMode++;
    if (currentMode == 4) {
      // RESET to 0 when MAX. 
      currentMode = 0;
    }
    switch_Mode(currentMode);
    delay(200);
    Keyboard.releaseAll();
    return 13;
 }
 else if(val>300){
    // Change TAB View
    Keyboard.press(KEY_LEFT_ALT); //Presses the LEFT ALT key.
    Keyboard.press(KEY_TAB); //Presses the TAB key.
    Keyboard.release(KEY_TAB); // Release Single Keypress.
    Keyboard.press(KEY_TAB); //Presses the TAB key.
    delay(200);
    Keyboard.releaseAll();
    return 14;
 }
 else if(val>260){
    // COPY
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press('c'); //Presses the C key.
    delay(200);
    Keyboard.releaseAll();
    return 15;
 }
 else if(val>200){
    // PASTE
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press('v'); //Presses the C key.
    delay(200);
    Keyboard.releaseAll();
    return 16;
 }
 else {
    return 0;
 }
    break;
 
 // MODE3 SETUP ******************************************
  case 2:
  // ALTERNATE MODE 2
  // get analog input value
 if(val>1000){
    Keyboard.press(KEY_F13); //Presses the F13 key.
    delay(200);
    Keyboard.releaseAll();
    return 1;
 }
 else if(val>900){
    Keyboard.press(KEY_F14); //Presses the F14 key.
    delay(200);
    Keyboard.releaseAll();
    return 2;
 }
 else if(val>820){
    Keyboard.press(KEY_F15); //Presses the F15 key.
    delay(200);
    Keyboard.releaseAll();
    return 3;
 }
 else if(val>750){
    Keyboard.press(KEY_F16); //Presses the F16 key.
    delay(200);
    Keyboard.releaseAll();
    return 4;
 }
 else if(val>660){
    Keyboard.press(KEY_F17); //Presses the F17 key.
    delay(200);
    Keyboard.releaseAll();
    return 5;
 }
 else if(val>620){
    Keyboard.press(KEY_F18); //Presses the F18 key.
    delay(200);
    Keyboard.releaseAll();
    return 6;
 }
 else if(val>585){
    Keyboard.press(KEY_F19); //Presses the F19 key.
    delay(200);
    Keyboard.releaseAll();
    return 7;
 }
 else if(val>540){
    Keyboard.press(KEY_F20); //Presses the F20 key.
    delay(200);
    Keyboard.releaseAll();
    return 8;
 }
 else if(val>500){
    Keyboard.press(KEY_F21); //Presses the F21 key.
    delay(200);
    Keyboard.releaseAll();
    return 9;
 }
 else if(val>475){
    Keyboard.press(KEY_F22); //Presses the F22 key.
    delay(200);
    Keyboard.releaseAll();
    return 10;
 }
 else if(val>455){
    Keyboard.press(KEY_F23); //Presses the F23 key.
    delay(200);
    Keyboard.releaseAll();
    return 11;
 }
 else if(val>425){
    Keyboard.press(KEY_F24); //Presses the F24 key.
    delay(200);
    Keyboard.releaseAll();
    return 12;
 }
 else if(val>370){
    // Switch Mode Button on 13
    // Add 1 to the Current Mode
    currentMode++;
    if (currentMode == 4) {
      // RESET to 0 when MAX. 
      currentMode = 0;
    }
    switch_Mode(currentMode);
    delay(200);
    Keyboard.releaseAll();
    return 13;
 }
 else if(val>300){
    // Change TAB View
    Keyboard.press(KEY_LEFT_ALT); //Presses the LEFT ALT key.
    Keyboard.press(KEY_TAB); //Presses the TAB key.
    Keyboard.release(KEY_TAB); // Release Single Keypress.
    Keyboard.press(KEY_TAB); //Presses the TAB key.
    delay(200);
    Keyboard.releaseAll();
    return 14;
 }
 else if(val>260){
    // COPY
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press('c'); //Presses the C key.
    delay(200);
    Keyboard.releaseAll();
    return 15;
 }
 else if(val>200){
    // PASTE
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press('v'); //Presses the C key.
    delay(200);
    Keyboard.releaseAll();
    return 16;
 }
 else {
    return 0;
 }
    break;

 // MODE 4 SETUP ******************************************
  case 3:
  // ALTERNATE MODE 3
  // get analog input value
 if(val>1000){
    Keyboard.press(KEY_F1); //Presses the F13 key.
    delay(200);
    Keyboard.releaseAll();
    return 1;
 }
 else if(val>900){
    Keyboard.press(KEY_F2); //Presses the F14 key.
    delay(200);
    Keyboard.releaseAll();
    return 2;
 }
 else if(val>820){
    Keyboard.press(KEY_F3); //Presses the F15 key.
    delay(200);
    Keyboard.releaseAll();
    return 3;
 }
 else if(val>750){
    Keyboard.press(KEY_F4); //Presses the F16 key.
    delay(200);
    Keyboard.releaseAll();
    return 4;
 }
 else if(val>660){
    Keyboard.press(KEY_F5); //Presses the F17 key.
    delay(200);
    Keyboard.releaseAll();
    return 5;
 }
 else if(val>620){
    Keyboard.press(KEY_F6); //Presses the F18 key.
    delay(200);
    Keyboard.releaseAll();
    return 6;
 }
 else if(val>585){
    Keyboard.press(KEY_F7); //Presses the F19 key.
    delay(200);
    Keyboard.releaseAll();
    return 7;
 }
 else if(val>540){
    Keyboard.press(KEY_F8); //Presses the F20 key.
    delay(200);
    Keyboard.releaseAll();
    return 8;
 }
 else if(val>500){
    Keyboard.press(KEY_F9); //Presses the F21 key.
    delay(200);
    Keyboard.releaseAll();
    return 9;
 }
 else if(val>475){
    Keyboard.press(KEY_F10); //Presses the F22 key.
    delay(200);
    Keyboard.releaseAll();
    return 10;
 }
 else if(val>455){
    Keyboard.press(KEY_F11); //Presses the F23 key.
    delay(200);
    Keyboard.releaseAll();
    return 11;
 }
 else if(val>425){
    Keyboard.press(KEY_F12); //Presses the F24 key.
    delay(200);
    Keyboard.releaseAll();
    return 12;
 }
 else if(val>370){
    // Switch Mode Button on 13
    // Add 1 to the Current Mode
    currentMode++;
    if (currentMode == 4) {
      // RESET to 0 when MAX. 
      currentMode = 0;
    }
    switch_Mode(currentMode);
    delay(200);
    Keyboard.releaseAll();
    return 13;
 }
 else if(val>300){
    // SAVE BUTTON
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press('s'); //Presses the C key.
    delay(200);
    Keyboard.releaseAll();
    return 14;
 }
 else if(val>260){
    // CLOSE CURRENT WINDOW WITHIN APPLICATION
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press('w'); //Presses the C key.
    delay(200);
    Keyboard.releaseAll();
    return 15;
 }
 else if(val>200){
    // QUIT PROGRAM
    Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
    Keyboard.press('q'); //Presses the C key.
    delay(200);
    Keyboard.releaseAll();
    return 16;
 }
 else {
    return 0;
 }
    break;
 }
  
}


// SET THE LED PINS BASED ON CURRENT MODE SELECTED
int switch_Mode(int mInt) {
  switch(mInt) {
    case 1:
    digitalWrite(MODE1, HIGH);
    digitalWrite(MODE2, LOW);
    digitalWrite(MODE3, LOW);
    currentMode = 1;
    Serial.println("Mode 1 Enabled");
    break;

    case 2:
    digitalWrite(MODE1, LOW);
    digitalWrite(MODE2, HIGH);
    digitalWrite(MODE3, LOW);
    currentMode = 2;
    Serial.println("Mode 2 Enabled");
    break;

    case 3:
    digitalWrite(MODE1, LOW);
    digitalWrite(MODE2, LOW);
    digitalWrite(MODE3, HIGH);
    currentMode = 3;
    Serial.println("Mode 3 Enabled");
    break;

    default:
    digitalWrite(MODE1, LOW);
    digitalWrite(MODE2, LOW);
    digitalWrite(MODE3, LOW);
    currentMode = 0;
    Serial.println("Default Mode Enabled");
    break;
  }
}

void setup() {
  // Keyboard Init
  Keyboard.begin();
  Consumer.begin();
  
  // Serial Port Init
  Serial.begin(9600);

  // Set LED Mode Indicators as OUTPUTs
  pinMode(MODE1, OUTPUT);
  pinMode(MODE2, OUTPUT);
  pinMode(MODE3, OUTPUT);

  // Delay Setup, wait for Init's
  delay(200);
}

void loop() {
 
 // Get value of analog input on Keypad
 int valueA1=analogRead(buttonPin);
 
 // Output data to serial port
 if (valueA1 > 100) {
  // Detected Button Press, now Flash LED & Brightness 1023 except MODE SWITCH
  if ((valueA1>370) && (valueA1<425)){analogWrite(flashLED, 0);} else {analogWrite(flashLED, 1023);} 
  // Which Button was Pressed?
  int pressedBtn = get_button(valueA1);
  // Write Findings to Serial
  Serial.println(valueA1);
  Serial.println(pressedBtn);   
 delay(150);
 // TURN OFF BUTTON PRESS LED REGARDLESS OF STATE / Brightness 0
 analogWrite(flashLED, 0);
 }
 
 // ENCCODER 1 SETUP
 if (encoderOneEnable == true) {
 /* Simple button press for knob momentary switch */
    stateVol = digitalRead(buttonMute) == LOW;
    if (stateVol == HIGH) {
      Consumer.write(MEDIA_VOLUME_MUTE);
      analogWrite(flashLED, 1023);
      Serial.println("ENCODER 1 Button Pressed!");
      delay(200);
      analogWrite(flashLED, 0);
    }

  /* React to changes of encoder */
    long newVolValue;  
    newVolValue = knobVol.read();
    if (newVolValue != volValue) { // Changed position
      if (newVolValue > volValue) { // Right turn
        Consumer.write(MEDIA_VOLUME_UP);
        Serial.println(knobVol.read());
      } else if (newVolValue < volValue) { // Left turn
        Consumer.write(MEDIA_VOLUME_DOWN);
        Serial.println(knobVol.read());
      }
      volValue = newVolValue;
    } }

// ENCCODER 2 SETUP
if (encoderTwoEnable == true) {
 /* Simple button press for knob momentary switch */
    stateVolTWO = digitalRead(buttonMuteTWO) == LOW;
    if (stateVolTWO == HIGH) {
      Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
      Keyboard.press('0'); //Reset Zoom Shortcut.
      Keyboard.releaseAll();
      analogWrite(flashLED, 1023);
      Serial.println("ENCODER 2 Button Pressed!");
      delay(200);
      analogWrite(flashLED, 0);
    }

  /* React to changes of encoder */
    long newVolValueTWO;  
    newVolValueTWO = knobVolTWO.read();
    if (newVolValueTWO != volValueTWO) { // Changed position
      if (newVolValueTWO > volValueTWO) { // Right turn
        Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
        Keyboard.press('+'); //Presses the Zoom In key.
        Keyboard.releaseAll();
        Serial.println(knobVolTWO.read());
      } else if (newVolValueTWO < volValueTWO) { // Left turn
        Keyboard.press(KEY_LEFT_CTRL); //Presses the CTRL key.
        Keyboard.press('-'); //Presses the Zoom Out key.
        Keyboard.releaseAll();
        Serial.println(knobVolTWO.read());
      }
      volValueTWO = newVolValueTWO;
    } }
    
}
