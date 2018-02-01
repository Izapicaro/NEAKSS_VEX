#pragma systemFile

#include "armLibrary.c"

//functions for autonomous (most were removed)

//moves backwards
void travelBackwards(Robot robot, int seconds){
	goForwards(robot,-127,-127);
	wait1Msec(seconds*1000);
	halt(robot);
}

//autonomous strategy 1
void auto1(Robot robot){

	//PART 1

	//close claw
	clawFunc(robot,127);
	wait1Msec(2000);
	endClaw(robot);

	//raise arm
	clawFunc(robot,127);
	armFunc(robot, 127);
	wait1Msec(2000);
	endArm(robot);
	endClaw(robot);

	//travel forwards
	clawFunc(robot,127);
	goForwards(robot,80,80);
	wait1Msec(1900);
	halt(robot);
	endClaw(robot);

	//lower arm
	armFunc(robot, -127);
	wait1Msec(3000);
	endArm(robot);

	//open claw
	clawFunc(robot, -127);
	wait1Msec(2000);
	endClaw(robot);

	//move backwards
	travelBackwards(robot,1.5);
	halt(robot);

	//PART 2

	//turn right
	turn(robot,50);
	wait1Msec(1500);
	halt(robot);

	//travel forwards
	goForwards(robot,50,50);
	wait1Msec(500);
	halt(robot);

	//close claw
	clawFunc(robot,127);
	wait1Msec(2000);
	endClaw(robot);

	//raise arm
	clawFunc(robot,127);
	armFunc(robot, 127);
	wait1Msec(2000);
	endArm(robot);
	endClaw(robot);

	//turn left
	turn(robot,-50);
	wait1Msec(1000);
	halt(robot);

	//travel forwards
	clawFunc(robot,127);
	goForwards(robot,80,80);
	wait1Msec(1900);
	halt(robot);
	endClaw(robot);

	//lower arm
	armFunc(robot, -127);
	wait1Msec(3000);
	endArm(robot);

	//open claw
	clawFunc(robot, -127);
	wait1Msec(2000);
	endClaw(robot);

	//move backwards
	travelBackwards(robot,1);
	halt(robot);


}
