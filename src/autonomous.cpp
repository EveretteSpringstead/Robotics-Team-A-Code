#include "vex.h"
#include "autonomous.h"

using namespace vex;

void blueLeft() {
  Drivetrain.setDriveVelocity(73, pct);
  Drivetrain.driveFor(forward, 23, inches);
  Drivetrain.turnFor(left, 25, degrees);

  left_lift.spin(forward, 82, pct);
  Drivetrain.setDriveVelocity(20, pct);
  wait(1, sec);

  Drivetrain.driveFor(forward, 20, inches);
  Drivetrain.setDriveVelocity(75, pct);
  wait(0.5, sec);

  Drivetrain.turnFor(left, 90, degrees);
  Drivetrain.driveFor(forward, 56, inches);
  Drivetrain.turnFor(left, 45, degrees);
  Drivetrain.driveFor(reverse, 30, inches);

  left_lift.spin(forward, 80, pct);
  right_lift.spin(reverse, 80, pct);
}

void redLeft() {
  Drivetrain.setDriveVelocity(73, pct);
  Drivetrain.driveFor(forward, 23, inches);
  Drivetrain.turnFor(left, 24, degrees);

  left_lift.spin(forward, 80, pct);
  Drivetrain.setDriveVelocity(20, pct);
  wait(1, sec);

  Drivetrain.driveFor(forward, 23.5, inches);
  Drivetrain.setDriveVelocity(60, pct);
  wait(1, sec);

  Drivetrain.turnFor(left, 95, degrees);
  Drivetrain.driveFor(reverse, 23.5, inches);

  right_lift.spin(reverse, 60, pct);
  left_lift.spin(forward, 60, pct);
  wait(4, sec);

  Drivetrain.driveFor(forward, 50, inches);
}

void blueRight() {
  Drivetrain.setDriveVelocity(73, pct);
  Drivetrain.driveFor(forward, 23, inches);
  Drivetrain.turnFor(right, 25, degrees);

  left_lift.spin(forward, 82, pct);
  Drivetrain.setDriveVelocity(20, pct);
  wait(1, sec);

  Drivetrain.driveFor(forward, 20, inches);
  Drivetrain.setDriveVelocity(75, pct);
  wait(0.5, sec);

  Drivetrain.turnFor(right, 90, degrees);
  Drivetrain.driveFor(forward, 56, inches);
  Drivetrain.turnFor(right, 43, degrees);
  Drivetrain.driveFor(reverse, 33, inches);

  left_lift.spin(forward, 80, pct);
  right_lift.spin(reverse, 80, pct);
}

void redRight() {
  Drivetrain.setDriveVelocity(73, pct);
  Drivetrain.driveFor(forward, 23, inches);
  Drivetrain.turnFor(right, 25, degrees);

  left_lift.spin(forward, 82, pct);
  Drivetrain.setDriveVelocity(20, pct);
  wait(1, sec);

  Drivetrain.driveFor(forward, 20, inches);
  Drivetrain.setDriveVelocity(75, pct);
  wait(0.5, sec);

  Drivetrain.turnFor(right, 90, degrees);
  Drivetrain.driveFor(forward, 56, inches);
  Drivetrain.turnFor(right, 45, degrees);
  Drivetrain.driveFor(reverse, 30, inches);

  left_lift.spin(forward, 80, pct);
  right_lift.spin(reverse, 80, pct);
}

void skills() {
  Drivetrain.setDriveVelocity(60, pct);
  Drivetrain.driveFor(forward, 24, inches);
  Drivetrain.turnFor(right, 25, degrees);

  left_lift.spin(forward, 82, pct);
  Drivetrain.setDriveVelocity(20, pct);
  wait(1, sec);

  Drivetrain.driveFor(forward, 20, inches);
  Drivetrain.setDriveVelocity(70, pct);
  wait(0.5, sec);

  Drivetrain.turnFor(right, 90, degrees);
  Drivetrain.driveFor(forward, 56, inches);
  Drivetrain.turnFor(right, 44, degrees);
  Drivetrain.driveFor(reverse, 35, inches);

  left_lift.spin(forward, 80, pct);
  right_lift.spin(reverse, 80, pct);
  Drivetrain.setDriveVelocity(60, pct);
  wait(4, sec);

  loader.set(true);
  right_lift.stop();
  Drivetrain.turnFor(right, 3, degrees);

  left_lift.spin(forward, 80, pct);
  Drivetrain.driveFor(forward, 48, inches);
  wait(0.5, sec);

  Drivetrain.driveFor(reverse, 8, inches);
  Drivetrain.driveFor(forward, 8, inches);
  wait(2, sec);

  Drivetrain.driveFor(reverse, 45, inches);
  left_lift.spin(forward, 80, pct);
  right_lift.spin(reverse, 80, pct);

  loader.set(false);
  wait(3, sec);

  Drivetrain.driveFor(forward, 15, inches);
  Drivetrain.turnFor(right, 48, degrees);
  Drivetrain.setDriveVelocity(100, pct);
  wait(1, sec);
  Drivetrain.driveFor(forward, 110, inches);
}
