//----------------------------------------------------------------------------
//                                                                            
//    Module:       main.cpp                                                  
//    Author:       BIRB                                                 
//    Created:      12/9/2023                                                    
//    Description:  IQ project                                                
//                                                                            
//----------------------------------------------------------------------------

#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <cstdint>

#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;

// START IQ MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END IQ MACROS

// Robot configuration code.
inertial BrainInertial = inertial();
motor flywheel = motor(PORT7, true);
pneumatic pusher = pneumatic(PORT8);

controller Controller = controller();

// define variable for remote controller enable/disable
#pragma endregion VEXcode Generated Robot Configuration

void flywheelforward() {
  flywheel.spin(forward);
  pusher.retract(cylinder2);
  wait(0.5, seconds);
  pusher.extend(cylinder2);
  Brain.playSound(siren);
}
void flywheelstop() {
  flywheel.stop();
}
int initialize() {
  flywheel.setVelocity(100, percent);
  flywheel.setMaxTorque(100, percent);
  flywheel.setStopping(coast);
  // Brain.Screen.setCursor(1, 1);
  // Brain.Screen.print("Calibrating");
  // BrainInertial.calibrate();
  // while (BrainInertial.isCalibrating()) { task::sleep(50); }
  // Brain.Screen.clearScreen();
  // Brain.Screen.setCursor(1, 1);
  // Brain.Screen.print("Calibrated");
  pusher.pumpOn();
  // printf("Calibrated");
  // BrainInertial.setHeading(0, degrees);
  // BrainInertial.setRotation(0, degrees);
  return 0;
}
int main() {
  Controller.ButtonRUp.pressed(flywheelforward);
  Controller.ButtonRDown.pressed(flywheelstop);
  wait(5, msec);
  initialize();
}
