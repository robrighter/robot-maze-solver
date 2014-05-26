/////////////////////////////////////////////////////////
// Maze Solver for 3pi robot
//
// AUTHOR: @robrighter 2014
////////////////////////////////////////////////////////
#include <pololu/3pi.h>
#include "path-chooser.h"

enum Direction make_path_choice(enum Junction_Type junction_type){
	switch(junction_type){
		case left_right_straight :
		case left_right :
		case left_straight :
			return left;
			break;
		case right_straight :
			return right;
			break;
		case dead_end :
			return back;
			break;
		default:
			return back;
			break;
	}
}

enum Junction_Type read_junction_type(){
	return  right_straight;
}

void turn(enum Direction direction){
	//turn the robot in the correct direction
}
