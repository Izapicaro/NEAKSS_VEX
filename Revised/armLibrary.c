#pragma systemFile

//includes movement library
#include "movementLibrary.c"

//arm function
void armFunc(Robot robot, int armPower){
	motor[robot.arm1] = armPower;
	motor[robot.arm2] = -armPower;
}

//claw function
void clawFunc(Robot robot, int clawPower){
	motor[robot.claw] = clawPower;
	motor[robot.claw2] = clawPower;
}

//claw extension
void extendClaw(Robot robot, int extendPower){
	motor[robot.clawExtension] = extendPower;
}

//arm-stopping function
void endArm(Robot robot){
	motor[robot.arm1] = 0;
	motor[robot.arm2] = 0;
}

//claw stopping function
void endClaw(Robot robot){
	motor[robot.claw] = 0;
}

//extension stopping function
void endExtension(Robot robot){
	motor[robot.clawExtension] = 0;
}
