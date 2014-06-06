//#include <pololu/orangutan.h>
#include <stdio.h>
#include <pololu/3pi.h>
#include "../../calibrate-for-line.h"

int main()
{
	clear(); print("Sensor"); lcd_goto_xy(0,1); print("Reader");
	
	while(1){
		while(!button_is_pressed(BUTTON_B)){}
		wait_for_button_release(BUTTON_B);
		delay_ms(1000);
		
		pololu_3pi_init(2000);
		calibrate_for_line();
		
		
		while(1){
			read_and_display_sensor_data();
			delay_ms(300);
		}
		set_motors(0,0);
	}
	
	//dont let the program ever reach the end of execution
	//or the robot may take over the world. Keep this code at
	//the bottom of the main just in case we screw up
	while(1){ delay_ms(2000); }
	return 0;
}