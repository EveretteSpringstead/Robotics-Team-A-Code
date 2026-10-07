#include "vex.h"
#include "autonomous.h"
#include "driver-control.h"

using namespace vex;

competition Competition;

namespace {
int currentAuton = 0;
bool autonStarted = false;
constexpr int kAutonCount = 5;

const char* autonomousName(int selection) {
  switch (selection) {
    case 0: return "Blue Left";
    case 1: return "Red Left";
    case 2: return "Blue Right";
    case 3: return "Red Right";
    case 4: return "Skills";
    default: return "Unknown";
  }
}
}  // namespace

void preAuton() {
  Brain.Screen.clearScreen();
  Brain.Screen.printAt(20, 40, "Calibrating Inertial...");

  InertialSensor.calibrate();
  while (InertialSensor.isCalibrating()) {
    wait(20, msec);
  }

  Brain.Screen.clearScreen();
  Brain.Screen.printAt(20, 40, "Inertial Ready");

  // Autonomous selector remains disabled for now.
  // while (!autonStarted) {
  //   Brain.Screen.clearScreen();
  //   Brain.Screen.printAt(50, 50, "%s", autonomousName(currentAuton));
  //
  //   if (Brain.Screen.pressing()) {
  //     while (Brain.Screen.pressing()) {
  //       wait(10, msec);
  //     }
  //
  //     currentAuton = (currentAuton + 1) % kAutonCount;
  //   }
  //
  //   wait(10, msec);
  // }
}


void autonomous() {
  autonStarted = true;

  switch (currentAuton) {
    case 0: blueLeft(); break;
    case 1: redLeft(); break;
    case 2: blueRight(); break;
    case 3: redRight(); break;
    case 4: skills(); break;
    default: break;
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(driverControl);

  preAuton();

  while (true) {
    wait(100, msec);
  }
}
