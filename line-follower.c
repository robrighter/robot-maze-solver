/////////////////////////////////////////////////////////
// LINE FOLLOWER for 3pi robot
// Uses a PID algo described here:
// http://www.chibots.org/?q=node/339
//
// AUTHOR: @robrighter 2012
////////////////////////////////////////////////////////

#include <pololu/3pi.h>

//Implementation of 

int last_proportional = 0;
int integral = 0;

//use these functions to tune the constants
int apply_kp(int p){
	return p/22;
}

int apply_kd(int d){
	//For initial tuning we set the constant to 0
	return d/4;
}

int apply_ki(int i){
	//For initial tuning we set the constant to 0
	return i/20000;
}

int get_value_within_max(int value, int max){
	if(value > max){
		return max;
	}
	else if(value < (-max)){
		return -max;
	}
	else{
		return value;
	}
}

void set_motors_by_position(int speed, unsigned int position){
	//Calculate the PID.
	
	//'P' = make 0 be on the line, 2000 is far to right, -2000 is far left
	int proportional = ((int)position) - 2000;
	//'I' = Aggregate of all 'P'
	integral += proportional;
	//'D' = Delta 'P'
	int derivative = proportional - last_proportional;
	
	//store off the proportional for future iteration
	last_proportional = proportional;
	
	//Actually calculate the speed.
	//The equation is P(kp) + I(ki) + D(kd)
	int d_speed = apply_kp(proportional) +
		apply_ki(integral) +
		apply_kd(derivative);
	
	//make sure the numbers dont get to big
	d_speed = get_value_within_max(d_speed, speed);
	
	//set the motors
	(d_speed< 0)?set_motors(speed+d_speed,speed):set_motors(speed,speed-d_speed);
}

void reset_line_follower(){
	last_proportional = 0;
	integral = 0;
}
