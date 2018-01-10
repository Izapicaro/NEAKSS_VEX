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

//moves right
void travelR(Robot robot, int seconds){
	goSideways(robot,127);
	wait1Msec(seconds*1000);
	halt(robot);
}

//moves left
void travelL(Robot robot, int seconds){
	goSideways(robot,-127);
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

	//pick up preload
	closeClaw(robot,1);
	//raise cone
	raiseArm(robot,3);
	//move towards stationary goal
	travelForwards(robot,3);
	//lower cone onto goal
	lowerArm(robot,1);
	//release cone onto goal
	openClaw(robot,1);
	//move claw away above goal
	raiseArm(robot,3);
	//rotate to correct orientation
	turnL(robot, 3);
	//move in front of cone
	travelL(robot,3);
	//lower claw to cone
	lowerArm(robot,3);
	//pick up cone
	closeClaw(robot,1);
	//raise cone
	raiseArm(robot,3);
	//travel to position in front of mobile goal
	travelR(robot,2);
	//move towards mobile goal
	travelForwards(robot,1);
	//lower cone onto goal
	lowerArm(robot,1);
	//release cone onto goal
	openClaw(robot,1);

}

//autonomous strategy 2
void auto2(Robot robot){

	//pick up preload
	closeClaw(robot,1);
	//raise cone
	raiseArm(robot,3);
	//move towards mobile goal
	travelForwards(robot,5);
	//lower cone onto goal
	lowerArm(robot,1);
	//release cone onto goal
	openClaw(robot,1);
	//move in line with match load
	travelBackwards(robot,2);
	//turn towards cone
	turnR(robot, 1);
	//lower claw to cone
	lowerArm(robot,3);
	//pick up cone
	closeClaw(robot,2);
	//turn towards mobile goal
	turnL(robot, 1);
	//move towards goal
	travelForwards(robot,2);
	//lower cone onto goal
	lowerArm(robot,2);
	//release cone onto goal
	openClaw(robot,2);
}

