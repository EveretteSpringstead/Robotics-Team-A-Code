
#include "vex.h"
using namespace vex;

brain Brain;
controller Controller;
inertial InertialSensor = inertial(PORT16);

motor LeftMotorA = motor (PORT1,ratio6_1,true);
motor LeftMotorB = motor (PORT11,ratio6_1,true);

motor RightMotorA = motor (PORT5,ratio6_1,false);
motor RightMotorB = motor (PORT15,ratio6_1,false);

motor left_lift = motor (PORT2,ratio18_1,false);
motor right_lift = motor (PORT8,ratio18_1,false);
motor claw = motor (PORT19,ratio18_1,false);
digital_out loader = digital_out (Brain.ThreeWirePort.A);
digital_out de_score = digital_out (Brain.ThreeWirePort.B);

motor_group LeftSmart = motor_group (LeftMotorA, LeftMotorB);
motor_group RightSmart = motor_group (RightMotorA, RightMotorB);

drivetrain Drivetrain = drivetrain (LeftSmart, RightSmart,8.6394,14,13,inches,1.25);

