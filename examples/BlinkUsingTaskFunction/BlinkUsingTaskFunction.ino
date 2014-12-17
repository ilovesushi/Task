// BlinkUsingTaskFunction
// This demonstrates the use of the FunctionTask feature of Task library
// It will use two FunctionTasks to to blink a LED repeatedly, by alternating 
// which task is active and flpping the state of the LED pin


#include <Task.h>

// Pin 13 has an LED connected on most Arduino boards.
int ledPin = 13;

TaskManager taskManager;

FunctionTask taskTurnLedOn(OnUpdateTaskLedOn, 400); // turn on the led in 400ms
FunctionTask taskTurnLedOff(OnUpdateTaskLedOff,600); // turn off the led in 600ms

void setup()
{
  pinMode(ledPin, OUTPUT);
  
  taskManager.StartTask(&taskTurnLedOn); // start with turning it on
}

void loop()
{
  taskManager.Loop();
}

void OnUpdateTaskLedOn(uint32_t deltaTimeMs)
{
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  taskManager.StopTask(&taskTurnLedOn); // stop trying to turn the LED On
  taskManager.StartTask(&taskTurnLedOff); // start the task to turn the LED off
}

void OnUpdateTaskLedOff(uint32_t deltaTimeMs)
{
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  taskManager.StopTask(&taskTurnLedOff); // stop trying to turn the LED Off
  taskManager.StartTask(&taskTurnLedOn); // start the task to turn the LED On
}

