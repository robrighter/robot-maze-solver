//#include <pololu/orangutan.h>
#include <stdio.h>
#include <pololu/3pi.h>
#include "calibrate-for-line.h"
#include "line-follower.h"

int main()
{
	clear(); print("Ready");
	
	while(1){
		while(!button_is_pressed(BUTTON_B)){}
		wait_for_button_release(BUTTON_B);
		delay_ms(1000);
		
		pololu_3pi_init(2000);
		calibrate_for_line();
		
		reset_line_follower();
		
		//just follow the line for a little while while testing
		while(1){
			set_motors_by_position(140,read_and_display_sensor_data());	
		}
		set_motors(0,0);
	}
	
	//dont let the program ever reach the end of execution
	//or the robot may take over the world. Keep this code at
	//the bottom of the main just in case we screw up
	while(1){ delay_ms(2000); }
	return 0;
}