#pragma config(Motor,  port1,           Right,         tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           Right2,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           Side,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           Claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           Arm1,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           Left2,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,          	Left,          tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

struct Robot {
	tMotor Left;
	tMotor Left2;
	tMotor Right;
	tMotor Right2;
	tMotor Side;
};

void go(Robot robot,int lPower, int rPower, int sPower){
	motor[robot.Left] = lPower;
	motor[robot.Left2] = lPower;
	motor[robot.Right] = rPower;
	motor[robot.Right2] = rPower;
	motor[robot.Side] = sPower;
}

void goForwards(Robot robot, int lPower, int rPower){
	go(robot,lPower,rPower,0);
}

task main(){

	Robot ROBOT;
	//ROBOT.Left = Left;
	//ROBOT.Left2 = Left2;
	//ROBOT.Right = Right;
	//ROBOT.Right2 = Right2;
	//ROBOT.Side = Side;

	while(1==1){

		if(vexRT[Btn8R]==1){
		goForwards(ROBOT,127,127);
		}

		if(vexRT[Btn8D]==1){
		goForwards(ROBOT,-127,-127);
		}

	}


}
