#include <string>
#include "Robots.h"

using namespace std;

void TurnLeft(Robot& r) // define turning left using turn right member function
{
	r.TurnRight();
	r.TurnRight();
	r.TurnRight();
}

void TurnBack(Robot& r) // define turning back using turn right member function
{
	r.TurnRight();
	r.TurnRight();
}

void moveRobots(Robot & Fiko, Robot & Fero, int xpos, int ypos) // move robots using given coordinates 
{
	if (xpos <= 7) // i divided first two main area according to x position of robot and applied for reflection robot
	{
		Fiko.Move(7 - xpos);
		Fero.Move(7 - xpos);

		if (ypos <= 8) // i also divided two area (under the ending x point or above the end x coordinate
		{
			TurnLeft(Fiko);
			Fero.TurnRight();
			Fiko.Move(8 - ypos);
			Fero.Move(8 - ypos);
		}

		else
		{
			Fiko.TurnRight();
			TurnLeft(Fero);
			Fiko.Move(ypos - 8);
			Fero.Move(ypos - 8);
		}
	}
	else // this part apply points of east of end point  
	{
		TurnBack(Fiko);
		TurnBack(Fero);
		Fiko.Move(xpos - 7);
		Fero.Move(xpos - 7);
		if (ypos <= 8)
		{
			Fiko.TurnRight();
			TurnLeft(Fero);
			Fiko.Move(8 - ypos);
			Fero.Move(8 - ypos);
		}
		else
		{
			TurnLeft(Fiko);
			Fero.TurnRight();
			Fiko.Move(ypos - 8);
			Fero.Move(ypos - 8);
		}

	}

}
int main()
{
	ShowMessage("This program moves the Player Robot to the target celland moves the Reflection Robot according to the Player Robot's movement.");
	int xpos, ypos;
	GetInput("Please Enter X position of the robot", xpos); // get info from user and check
	if (xpos >= 0 && xpos < 14)
		true;
	else // if input not in the interval show this massage
		ShowMessage("Invalid X coordinate!");
	GetInput("Please Enter Y position of the robot", ypos);
	if (ypos >= 0 && ypos < 14) // apply for y what x is done
		true;
	else
		ShowMessage("Invalid Y coordinate!");
	Robot Fiko(xpos, ypos, east);
	Robot Fero(27 - xpos, ypos, west); // create robot and reflection
	Fiko.SetColor(blue);
	Fero.SetColor(red); // pot color for them
	moveRobots(Fiko, Fero, xpos, ypos); // call the function
	Fiko.SetColor(red);
	Fero.SetColor(blue);// change the color

	return 0;
}