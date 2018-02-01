/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        		  NEAKSS VEX ROBOTICS CODE                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/

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
	ROBOT.left = port2;
	ROBOT.left2 = port6;
	ROBOT.right = port10;
	ROBOT.right2 = port1;
	ROBOT.arm1 = port3;
	ROBOT.arm2 = port8;
	ROBOT.arm3 = port4;
	ROBOT.arm4 = port9;
	ROBOT.claw = port5;
	ROBOT.claw2 = port7;

  bStopTasksBetweenModes = true;

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/

task autonomous(){

	auto1(ROBOT);

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
			else if(abs(vexRT[Ch4])>0){
				turn(ROBOT,vexRT[Ch4]);
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
				motor[ROBOT.arm2] = vexRT[Ch3Xmtr2];
				motor[ROBOT.arm3] = -vexRT[Ch2Xmtr2];
				motor[ROBOT.arm4] = vexRT[Ch2Xmtr2];
			}

			//close claw
			if(vexRT[Btn6UXmtr2]==1){
				clawFunc(ROBOT,127);
			}

			//open claw
			else if(vexRT[Btn6DXmtr2]==1){
				clawFunc(ROBOT,-127);
			}

			//stop claw
			else {
				endClaw(ROBOT);
			}

		}

}
