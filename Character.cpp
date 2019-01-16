/*********************************************************************
** Program Name:    Fantasy Combat Tournament
** Author:          Melisa Lee
** Date:            11/18/2018
** Description:     Character.cpp is the Character class function 
		    implemenation file.
*********************************************************************/
#include "Character.hpp"

#include <ctime>
#include <cstdlib>

/*********************************************************************
** Description: Default constructor.
**********************************************************************/
Character::Character()
{
	
}

/*********************************************************************
** Description: This constructor takes in two integers: armorPoint and
		sp and a string for the character name set the member
		variable.
**********************************************************************/
Character::Character(int armorPoint, int sp, string charName, int type)
{
	srand((unsigned)time(0));

	armor = armorPoint;
	strengthPoint = sp;
	name = charName;
	startingSP = sp;
	charType = type;
}
 
/*********************************************************************
** Description: This function accepts no parameter and returns an 
		integer based on the character's armor.
*********************************************************************/
int Character::getArmor()
{
	return armor;
}

/*********************************************************************
** Description: This function accepts no parameter and returns an
		integer based on the character's strength points.
*********************************************************************/
int Character::getSP()
{
	return strengthPoint;
}

/*********************************************************************
** Description: This function accepts no parameter and returns an
		string based on the character's name.
*********************************************************************/
string Character::getName()
{
	return name;
}

/*********************************************************************
** Description: This function accepts no parameter and return a boolean
		if a character is alive.
*********************************************************************/
bool Character::getAlive()
{
	return alive;
}

/*********************************************************************
** Description: This function accepts no parameter. Return a string
		representing the character type.
*********************************************************************/
string Character::getCharType()
{
	if (charType == 1)
	{
		return "Vampire";
	}
	else if (charType == 2)
	{
		return "Barbarian";
	}
	else if (charType == 3)
	{
		return "Blue Men";
	}
	else if (charType == 4)
	{
		return "Medusa";
	}
	else
	{
		return "Harry Potter";
	}
}

/*********************************************************************
** Description: This function accepts two integer a min and max. Return
		a randomly generated number between those ranges.
*********************************************************************/
int Character::randomNum(int min, int max)
{
	return (rand() % (max - min + 1) + min);
}


/*********************************************************************
** Description: This function accepts no parameter. Recover half the 
		damage taken by a character.
*********************************************************************/
void Character::recovery()
{	
	strengthPoint += ((startingSP - strengthPoint) / 2);
}
