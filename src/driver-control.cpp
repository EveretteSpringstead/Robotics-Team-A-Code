#include "vex.h"
#include "driver-control.h"

using namespace vex;

namespace {
constexpr int kMechanismSpeedPct = 100;

void updateDrive() {
  double tilt = InertialSensor.pitch(degrees);
  if (tilt < 0.0) {
    tilt = -tilt;
  }

  double antiTipMultiplier = 1.0;

  // Progressively reduce drive power as the robot tilts.
  if (tilt >= 20.0) {
    LeftMotorA.stop(brake);
    LeftMotorB.stop(brake);
    RightMotorA.stop(brake);
    RightMotorB.stop(brake);
    return;
  } else if (tilt >= 17.0) {
    antiTipMultiplier = 0.30;
  } else if (tilt >= 12.0) {
    antiTipMultiplier = 0.60;
  }

  const double forwardPower = Controller.Axis3.position() * antiTipMultiplier;
  const double turnPower = Controller.Axis1.position() * antiTipMultiplier;

  double leftPower = forwardPower + turnPower;
  double rightPower = forwardPower - turnPower;

  // Clamp the final commands to the VEX motor percentage range.
  if (leftPower > 100.0) leftPower = 100.0;
  if (leftPower < -100.0) leftPower = -100.0;
  if (rightPower > 100.0) rightPower = 100.0;
  if (rightPower < -100.0) rightPower = -100.0;

  LeftMotorA.spin(forward, leftPower, pct);
  LeftMotorB.spin(forward, leftPower, pct);
  RightMotorA.spin(forward, rightPower, pct);
  RightMotorB.spin(forward, rightPower, pct);
}


void updateLift() {
  if (Controller.ButtonL1.pressing()) {
    left_lift.spin(forward, kMechanismSpeedPct, pct);
    right_lift.spin(reverse, kMechanismSpeedPct, pct);
  } else if (Controller.ButtonL2.pressing()) {
    left_lift.spin(reverse, kMechanismSpeedPct, pct);
    right_lift.spin(forward, kMechanismSpeedPct, pct);
  } else {
    left_lift.stop(hold);
    right_lift.stop(hold);
  }
}

void updateClaw() {
  if (Controller.ButtonR1.pressing()) {
    claw.spin(forward, kMechanismSpeedPct, pct);
  } else if (Controller.ButtonR2.pressing()) {
    claw.spin(reverse, kMechanismSpeedPct, pct);
  } else {
    claw.stop(hold);
  }
}

void updatePneumatics() {
  if (Controller.ButtonB.pressing()) {
    loader.set(true);
  } else if (Controller.ButtonY.pressing()) {
    loader.set(false);
  }

  if (Controller.ButtonA.pressing()) {
    de_score.set(true);
  } else if (Controller.ButtonX.pressing()) {
    de_score.set(false);
  }
}
}  // namespace

void driverControl() {
  while (true) {
    updateDrive();
    updateLift();
    updateClaw();
    updatePneumatics();

    wait(20, msec);
  }
}
