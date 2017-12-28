#pragma config(Motor,  port1,            ,             tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,            ,             tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "armLibrary.c"

task main(){

	//set up
	Robot ROBOT;
	ROBOT.left = port1;
	ROBOT.left2 = port3;
	ROBOT.right = port2;
	ROBOT.right2 = port4;
	ROBOT.side = port5;
	ROBOT.arm1 = port6;
	ROBOT.arm2 = port7;
	ROBOT.claw = port8;

	while(1==1){

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

		//raise arm
		else if(vexRT[Btn5U]==1){
			armFunc(ROBOT,127);
		}

		//lower arm
		else if(vexRT[Btn5D]==1){
			armFunc(ROBOT,-127);
		}

		//open claw
		else if(vexRT[Btn6U]==1){
			clawFunc(ROBOT,127);
		}

		//close claw
		else if(vexRT[Btn6D]==1){
			clawFunc(ROBOT,-127);
		}

		//stop if no buttons are pressed
		else{
			halt(ROBOT);
			endPick(ROBOT);
		}

	}

}