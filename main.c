//#include <pololu/orangutan.h>
#include <pololu/3pi.h>
#include "calibrate-for-line.h"

int main()
{
	
	while(1){
		while(!button_is_pressed(BUTTON_B)){}
		wait_for_button_release(BUTTON_B);
		
		pololu_3pi_init(2000);
		calibrate_for_line();
		read_and_display_sensor_data();	
	}
	
	//dont let the program ever reach the end of execution
	//or the robot may take over the world
	return 0;
}

// Local Variables: **
// mode: C **
// c-basic-offset: 4 **
// tab-width: 4 **
// indent-tabs-mode: t **
// end: **
