#pragma systemFile

//includes movement library
#include "movementLibrary.c"

//overall arm function
void pick(Robot robot, int armPower, int clawPower){
	motor[robot.arm1] = armPower;
	motor[robot.arm2] = armPower;
	motor[robot.claw] = clawPower;
}

//lift and lower arm
void armFunc(Robot robot, int armPower){
	pick(robot, armPower, 0);
}

void clawFunc(Robot robot, int clawPower){
	pick(robot, 0, clawPower);
}

void endPick(Robot robot){
	pick(robot, 0, 0);
}
