#pragma systemFile

struct Robot {
	//properties of Robot struct
	tMotor left;
	tMotor left2;
	tMotor right;
	tMotor right2;
	tMotor side;
	tMotor arm1;
	tMotor arm2;
	tMotor claw;
	tMotor claw2;
	tMotor clawExtension;
};

//overall movement
void go(Robot robot, int lPower, int rPower, int sPower){
	motor[robot.left] = lPower;
	motor[robot.left2] = lPower;
	motor[robot.right] = -rPower;
	motor[robot.right2] = -rPower;
	motor[robot.side] = sPower;
}

//moving forwards/backwards
void goForwards(Robot robot, int lPower, int rPower){
	go(robot,lPower,rPower,0);
}

//moving sideways
void goSideways(Robot robot, int sPower){
	go(robot,0,0,sPower);
}

//stopping
void halt(Robot robot){
	go(robot,0,0,0);
}

//turning
void turn(Robot robot, int speed){
	go(robot,speed,-speed,0);
}
