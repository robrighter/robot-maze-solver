#include <pololu/3pi.h>
#include <avr/pgmspace.h>

#define CALIBRATE_COUNTER 80
#define CALIBRATE_DELAY 20
#define CALIBRATE_MOTOR_SPEED 40
#define NUMBER_OF_SENSORS 5

void calibrate_for_line(){
	//rotate far left, then far right, then back to center while taking readings
	for(int i=0; i<CALIBRATE_COUNTER; i++){
		if(i < 20 || i >= 60){
			set_motors(CALIBRATE_MOTOR_SPEED,-CALIBRATE_MOTOR_SPEED);
		}
		else{
			set_motors(-CALIBRATE_MOTOR_SPEED,CALIBRATE_MOTOR_SPEED);
		}
		calibrate_line_sensors(IR_EMITTERS_ON);
		delay_ms(CALIBRATE_DELAY);
	}
	//stop motors, we're all done
	set_motors(0,0);
}

void read_and_display_sensor_data(){
	unsigned int values[NUMBER_OF_SENSORS];
	unsigned int position = read_line(values,IR_EMITTERS_ON);
	//print the position on the top line and the values on the 2nd line
	clear();
	print_long(position);
	lcd_goto_xy(0,1);
	const char displayable[10] = {'0','1','2','3','4','5','6','7','8','9'};
	for(int i=0; i<NUMBER_OF_SENSORS; i++){
		//translate the reading into a displayable value (0-9)
		char c = displayable[values[i]/101];
		print_character(c);
	}
}