#pragma once

#include "v5.h"
#include "v5_vcs.h"

using namespace vex;

// Competition hardware
extern brain Brain;
extern controller Controller;
extern inertial InertialSensor;

// Drive motors
extern motor LeftMotorA;
extern motor LeftMotorB;
extern motor RightMotorA;
extern motor RightMotorB;

// Mechanism motors
extern motor left_lift;
extern motor right_lift;
extern motor claw;

// Pneumatics
extern digital_out loader;
extern digital_out de_score;

// Drive groups and drivetrain
extern motor_group LeftSmart;
extern motor_group RightSmart;
extern drivetrain Drivetrain;
