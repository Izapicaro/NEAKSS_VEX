#pragma systemFile

#include "armLibrary.c"

//functions for autonomous

//closes claw
void closeClaw(Robot robot, int seconds){
	clawFunc(robot, -127);
	wait1Msec(seconds*1000);
	endClaw(robot);
}

//opens claw
void openClaw(Robot robot, int seconds){
	clawFunc(robot, 127);
	wait1Msec(seconds*1000);
	endClaw(robot);
}

//raises arm
void raiseArm(Robot robot, int seconds){
	armFunc(robot, 127);
	wait1Msec(seconds*1000);
	endArm(robot);
}

//lowers arm
void lowerArm(Robot robot, int seconds){
	armFunc(robot, -127);
	wait1Msec(seconds*1000);
	endArm(robot);
}

//moves forwards
void travelForwards(Robot robot, int seconds){
	goForwards(robot,127,127);
	wait1Msec(seconds*1000);
	halt(robot);
}

//moves backwards
void travelBackwards(Robot robot, int seconds){
	goForwards(robot,-127,-127);
	wait1Msec(seconds*1000);
	halt(robot);
}

//turns left
void turnL(Robot robot, int seconds){
	turn(robot, -127);
	wait1Msec(seconds*1000);
	halt(robot);
}

//turns right
void turnR(Robot robot, int seconds){
	turn(robot, -127);
	wait1Msec(seconds*1000);
	halt(robot);
}

//autonomous strategy 1
void auto1(Robot robot){

	//travel forwards
	travelForwards(robot,2);

}
