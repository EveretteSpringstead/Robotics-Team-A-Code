# 22002A VEX V5 Project

This project is organized so each file has one clear responsibility.

## Project Structure

- `src/main.cpp` - Competition setup and autonomous selection.
- `src/robot-config.cpp` - Physical robot devices, ports, motor groups, and drivetrain configuration.
- `src/autonomous.cpp` - Autonomous routines only.
- `src/driver-control.cpp` - Driver-control logic only.
- `include/robot-config.h` - Declares robot hardware used by the rest of the program.
- `include/autonomous.h` - Declares autonomous routines.
- `include/driver-control.h` - Declares the driver-control function.
- `include/vex.h` - Shared VEX SDK includes and helper macros.

## Driver Controls

- Left stick Axis 3: forward/reverse
- Left stick Axis 1: turning
- L1 / L2: raise / lower lift
- R1 / R2: open / close claw
- B / Y: loader piston on/off
- A / X: de-scoring piston on/off

## Autonomous Selection

Before a match, tap the V5 Brain screen to cycle through:

1. Blue Left
2. Red Left
3. Blue Right
4. Red Right
5. Skills

## Organization Notes

The original project had a circular header dependency because `robot-config.h` included `vex.h` while `vex.h` included `robot-config.h`. The revised structure removes that dependency. Driver-control logic was also moved out of `main.cpp` so the competition flow is easier to read and explain.
