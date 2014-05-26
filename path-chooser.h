/////////////////////////////////////////////////////////
// Maze Solver for 3pi robot
//
// AUTHOR: @robrighter 2014
////////////////////////////////////////////////////////

enum Junction_Type
{
	left_right_straight,
	left_right,
	left_straight,
	right_straight,
	dead_end
};

enum Direction
{
	left,
	right,
	straight,
	back
};

enum Direction make_path_choice(enum Junction_Type junction_type);

enum Junction_Type read_junction_type();

void turn(enum Direction direction);

