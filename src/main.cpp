#include <Arduino.h>
#include <Keyboard.h>
#include <Bounce2.h>
#include <jled.h>


//// DEFINITIONS

// INPUTS
#define BUTTON1_PIN 2
#define PIR_PIN 3

// OUTPUTS
#define LED1_PIN 10

// OBJECTS
Bounce2::Button button1 = Bounce2::Button();
JLed led1 = JLed(LED1_PIN).LowActive();

// FUNCTIONS
void Update(){
  button1.update();
  led1.Update();
  Keyboard.releaseAll();
}

void activateScreen(){
  Keyboard.write(KEY_SCROLL_LOCK);
}

void rebootSystem(){
  //trigger Keyboard Shortcut CTRL + ALT + r
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('r');
}


void setup() { 
  // BUTTON1
  button1.attach(BUTTON1_PIN, INPUT_PULLUP);
  button1.setPressedState(LOW);
  button1.interval(5);
  
  // PIR
  pinMode(PIR_PIN, INPUT);

  // LED1
  led1.Off(); //LowActive LED
}

void loop()
{
  Update();

  if(button1.isPressed()){
    led1.On();
  }

  // BUTTON LONG

  if(button1.isPressed() && button1.currentDuration() > 5000){ 
    led1.Blink(500,500).Repeat(40);
    rebootSystem();
    while (led1.IsRunning()) //Warte bis alle Blinktakte abgelaufen sind (Dauer des Reboots)
    {
      Update();
    }
    
  }

  // BUTTON SHORT

  if (button1.released() && button1.previousDuration() < 1000) {
    activateScreen();
    led1.Blink(50,50).Repeat(10);
  }

  // PIR SENSOR

  if(digitalRead(PIR_PIN) && !led1.IsRunning()){
    activateScreen();
    led1.Blink(100,100).Repeat(15);
  }
  
}

