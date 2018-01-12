/*NEAKSS VEX ROBOTICS Code

//This code is for the VEX cortex platform
#pragma platform(VEX2)

//Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code
#include "Vex_Competition_Includes.c"

//Custom library
#include "autonomous1.c"

Robot ROBOT;


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	//construct robot
	ROBOT.left = port3;
	ROBOT.left2 = port4;
	ROBOT.right = port1;
	ROBOT.right2 = port10;
	ROBOT.arm1 = port5;	
	ROBOT.arm2 = port2;
	ROBOT.arm3 = port6;
	ROBOT.arm4 = port8;
	ROBOT.claw = port7;
	ROBOT.claw2 = port9;
	
  bStopTasksBetweenModes = false;

	bDisplayCompetitionStatusOnLcd = false;
	
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/

task autonomous(){
	
	//autonomous has not been triggered
	int autonomous;
	autonomous = 0;
	
	//pressing 7U triggers autonomous
	if(vexRT[Btn7U]==1){
		autonomous = 1;
	}
	
	if(autonomous==1){
		//run autonomous code
		auto1(ROBOT);
	}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*---------------------------------------------------------------------------*/

task usercontrol(){
	
		//once out of the autonomous period
		while(true){
	
			//move forwards
			if(vexRT[Btn8R]==1){
				goForwards(ROBOT,127,127);
	
			}
	
			//move backwards
			else if(vexRT[Btn8D]==1){
				goForwards(ROBOT,-127,-127);
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
				motor[ROBOT.arm1] = -vexRT[Ch3Xmtr2];
				motor[ROBOT.arm2] = -vexRT[Ch3Xmtr2];
				motor[ROBOT.arm3] = vexRT[Ch2Xmtr2];
				motor[ROBOT.arm4] = vexRT[Ch2Xmtr2];
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
