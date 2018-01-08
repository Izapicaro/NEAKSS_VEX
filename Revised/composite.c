#include "autonomous1.c"

task main(){

	//changes value after autonomous
	int autonomous;
	autonomous = 1;

	//set up
	Robot ROBOT;
	ROBOT.left = port4;
	ROBOT.left2 = port5;
	ROBOT.right = port1;
	ROBOT.right2 = port2;
	ROBOT.side = port3;
	ROBOT.arm1 = port6;
	ROBOT.arm2 = port7;
	ROBOT.claw = port8;


	//while the autonomous period is ongoing
	while(autonomous == 1){

		if(vexRT[Btn7U]==1){
			//runs first autonomous strategy
			auto1(ROBOT);
			autonomous = 0;
		}

		else if(vexRT[Btn7D]==1){
			//runs second autonomous strategy
			auto2(ROBOT);
			autonomous = 0;
		}

		else if(vexRT[Btn7R]==1){
			//skips both autonomous strategies
			autonomous = 0;
		}

	}

	//once out of the autonomous period
	while(autonomous == 0){

		//move forwards
		if(vexRT[Btn8R]==1){
			goForwards(ROBOT,127,127);

		}

		//move backwards
		else if(vexRT[Btn8D]==1){
			goForwards(ROBOT,-127,-127);
		}

		//move sideways
		else if(abs(vexRT[Ch4])>0){
			goSideways(ROBOT,vexRT[Ch4]);
		}

		//turn
		else if(abs(vexRT[Ch1])>0){
			turn(ROBOT,vexRT[Ch1]);
		}

		//stop
		else{
			halt(ROBOT);
		}

		//raise arm
		if(vexRT[Btn5UXmtr2]==1){
			armFunc(ROBOT,127);
		}

		//lower arm
		else if(vexRT[Btn5DXmtr2]==1){
			armFunc(ROBOT,-127);
		}

		//switch arm controls to joysticks in case they become out of sync
		else{
			motor[ROBOT.arm1] = vexRT[Ch3Xmtr2];
			motor[ROBOT.arm2] = vexRT[Ch2Xmtr2];
		}

		//open claw
		if(vexRT[Btn6UXmtr2]==1){
			clawFunc(ROBOT,127);
		}

		//close claw
		else if(vexRT[Btn6DXmtr2]==1){
			clawFunc(ROBOT,-127);
		}

		//stop claw
		else {
			endClaw(ROBOT);
		}


	}

}
