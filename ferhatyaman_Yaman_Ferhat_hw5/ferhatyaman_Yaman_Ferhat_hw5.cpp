#include <string>
#include "Robots_Modified.h"
#include "miniFW_Modified.h"
#include "strutils.h"
using namespace std;

void ActionBoulder(Robot & player, Robot & robot) // this function move boulder robots i generilized for three boulders.
{
	if (robot.Blocked() == true)
	{
		robot.TurnFace(player.GetDirection()); // i creat new member function ( GetDirection) this take robot's direction. turn player robot direction
		if (!robot.Blocked())
		{
			while (robot.Blocked() == false) // if it is not blocked move!!
			{
				robot.Move();

			}

			robot.Resurrect();
		}
	}
	else //when it is blocked, just turn robot into player direction
	{
		robot.TurnFace(player.GetDirection());
		while (robot.Blocked() == false)
		{
			robot.Move();

		}

		robot.Resurrect();
	}
}


void FindBoulder(Robot & player, Robot & boulder1, Robot & boulder2, Robot & boulder3) // this function find boulder and where is player which side of boulder and check does the player push boulder
{
	if ((player.GetXCoordinate() + 1 == boulder1.GetXCoordinate() && (player.GetYCoordinate() == boulder1.GetYCoordinate()) && player.GetDirection() == east)) 
		ActionBoulder(player, boulder1);
	if ((player.GetXCoordinate() == boulder1.GetXCoordinate() && (player.GetYCoordinate() - 1 == boulder1.GetYCoordinate()) && player.GetDirection() == south))
		ActionBoulder(player, boulder1);
	if ((player.GetXCoordinate() - 1 == boulder1.GetXCoordinate() && (player.GetYCoordinate() == boulder1.GetYCoordinate()) && player.GetDirection() == west))
		ActionBoulder(player, boulder1);
	if ((player.GetXCoordinate() == boulder1.GetXCoordinate() && (player.GetYCoordinate() + 1 == boulder1.GetYCoordinate()) && player.GetDirection() == north))
		ActionBoulder(player, boulder1);

	if ((player.GetXCoordinate() + 1 == boulder2.GetXCoordinate() && (player.GetYCoordinate() == boulder2.GetYCoordinate()) && player.GetDirection() == east))
		ActionBoulder(player, boulder2);
	if ((player.GetXCoordinate() == boulder2.GetXCoordinate() && (player.GetYCoordinate() - 1 == boulder2.GetYCoordinate()) && player.GetDirection() == south))
		ActionBoulder(player, boulder2);
	if ((player.GetXCoordinate() - 1 == boulder2.GetXCoordinate() && (player.GetYCoordinate() == boulder2.GetYCoordinate()) && player.GetDirection() == west))
		ActionBoulder(player, boulder2);
	if ((player.GetXCoordinate() == boulder2.GetXCoordinate() && (player.GetYCoordinate() + 1 == boulder2.GetYCoordinate()) && player.GetDirection() == north))
		ActionBoulder(player, boulder2);

	if ((player.GetXCoordinate() + 1 == boulder3.GetXCoordinate() && (player.GetYCoordinate() == boulder3.GetYCoordinate()) && player.GetDirection() == east))
		ActionBoulder(player, boulder3);
	if ((player.GetXCoordinate() == boulder3.GetXCoordinate() && (player.GetYCoordinate() - 1 == boulder3.GetYCoordinate()) && player.GetDirection() == south))
		ActionBoulder(player, boulder3);
	if ((player.GetXCoordinate() - 1 == boulder3.GetXCoordinate() && (player.GetYCoordinate() == boulder3.GetYCoordinate()) && player.GetDirection() == west))
		ActionBoulder(player, boulder3);
	if ((player.GetXCoordinate() == boulder3.GetXCoordinate() && (player.GetYCoordinate() + 1 == boulder3.GetYCoordinate()) && player.GetDirection() == north))
		ActionBoulder(player, boulder3);
}


int main()
{
	Robot player(0,0,east,50); // create player robot and set color as blue
	player.SetColor(blue);
	
	int x1, y1;
	GetInput("Please enter the X coordinate for boulder 1", x1); // get x and y for all boulder and set colors
	GetInput("Please enter the Y coordinate for boulder 1", y1);
	Robot boulder1(x1, y1);
	boulder1.SetColor(yellow);

	int x2, y2;
	GetInput("Please enter the X coordinate for boulder 2", x2);
	GetInput("Please enter the Y coordinate for boulder 2", y2);
	Robot boulder2(x2, y2);
	boulder2.SetColor(green);

	int x3, y3;
	GetInput("Please enter the X coordinate for boulder 3", x3);
	GetInput("Please enter the Y coordinate for boulder 3", y3);
	Robot boulder3(x3, y3);
	boulder3.SetColor(pink);



	while (!((boulder1.GetXCoordinate() == 10 && boulder1.GetYCoordinate() == 10) || (boulder2.GetXCoordinate() == 10 && boulder2.GetYCoordinate() == 10) || (boulder3.GetXCoordinate() == 10 && boulder3.GetYCoordinate() == 10)) && player.GetBagCount() > 0)
	{
		if (IsPressed(keyRightArrow)) // in the while, i check that does it win or lose game other of this condition while will return 
		{
			player.TurnFace(east); // every if describe key and what they this key do


			if (player.Blocked()) // when player blocked  it can not move then boulder or wall can be in front of player
			{ 
				player.Resurrect();
				if (!player.FacingWall()) // if not facing wall thereis boulder and move boulder
					FindBoulder(player, boulder1, boulder2, boulder3);
				
			}
				
			
			else // else move and decrease bag 
			{
				player.Move();
				player.DecreaseBag();
				player.PickAllThings();
			}
		}
		else if (IsPressed(keyLeftArrow)) // do same things for each direction and key
		{
			player.TurnFace(west);
			if (player.Blocked())
			{
				player.Resurrect();
				if (!player.FacingWall())
					FindBoulder(player, boulder1, boulder2, boulder3);
			}
			else
			{
				player.Move();
				player.DecreaseBag();
				player.PickAllThings();
			}
			
		}
		else if (IsPressed(keyUpArrow))
		{
			player.TurnFace(north);
			if (player.Blocked())
			{
				player.Resurrect();
				if (!player.FacingWall())
					FindBoulder(player, boulder1, boulder2, boulder3);
			}
			else
			{
				player.Move();
				player.DecreaseBag();
				player.PickAllThings();
			}
			
		}
		else if (IsPressed(keyDownArrow))
		{
			player.TurnFace(south);
			if (player.Blocked())
			{
				player.Resurrect();
				if (!player.FacingWall())
					FindBoulder(player, boulder1, boulder2, boulder3);
			}
			else
			{
				player.Move();
				player.DecreaseBag();
				player.PickAllThings();
			}
		}
			
		else if (IsPressed(keyHome)) // this keyteleport all robots initial position but first teleport out of world to not die robots and then teleport their initial position
		{
			player.Teleport(50, 50, east);
			boulder1.Teleport(50, 51, east);
			boulder2.Teleport(50, 52, east);
			boulder3.Teleport(50, 53, east);
			player.Teleport(0, 0, east);
			player.SetBagCount(50);
			boulder1.Teleport(x1, y1, east);
			boulder2.Teleport(x2, y2, east);
			boulder3.Teleport(x3, y3, east);


		}
		
	}
	if (((boulder1.GetXCoordinate() == 10 && boulder1.GetYCoordinate() == 10) || (boulder2.GetXCoordinate() == 10 && boulder2.GetYCoordinate() == 10) || (boulder3.GetXCoordinate() == 10 && boulder3.GetYCoordinate() == 10)) && player.GetBagCount() >= 0)
	{
		int bag = player.GetBagCount(); // if there is a  boulder (10,10), user wins the game except bag == 0 
		ShowMessage("Congratulations, solved the puzzle with " + itoa(bag) + " energy!");

	}
	else// if amount of things finish in the bag, user lose the game and c out final position of player  
	{
		int x = player.GetXCoordinate();
		int y = player.GetYCoordinate();
		ShowMessage("You couldn't reach to exit in time and blacked out in " + itoa(x) + ", " + itoa(y));
	}

	


	return 0;
}