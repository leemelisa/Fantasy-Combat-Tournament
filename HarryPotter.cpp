/*******************************************************************
** Program Name:    Fantasy Combat Tournament
** Author:          Melisa Lee
** Date:            11/18/2018
** Description:     HarryPotter.cpp is the HarryPotter class function
		    implemenation file.
*********************************************************************/
#include "HarryPotter.hpp"

#include <iostream>
using std::endl;
using std::cout;

/*********************************************************************
** Description: This constructor takes in three integers: armorPoint,
		sp and character type; one string: character name.
		Set the member variable of Harry Potter class.
*********************************************************************/
HarryPotter::HarryPotter(int armorPoint, int sp, string charName, int type) :Character(armorPoint, sp, charName, type)
{

}

/*********************************************************************
** Description: This function accepts no parameter. Calculates and
		return damage attacked by the attacker.
*********************************************************************/
int HarryPotter::calculateAtk()
{
	// calculate attacker's roll
	int firstRoll = randomNum(1, 6);
	int secondRoll = randomNum(1, 6);

	return (firstRoll + secondRoll);
}

/*********************************************************************
** Description: This function accepts a parameter: integer damage
		attack. Calculate the acutal damage inflicted and apply
		the damage to the defender's strength point.
*********************************************************************/
void HarryPotter::calculateDef(int atk)
{
	int actualDmg;
	int def;
	//calculate defender's roll
	int firstRoll = randomNum(1, 6);
	int secondRoll = randomNum(1, 6);

	// display results to user
	def = (firstRoll + secondRoll);

	// calculate actual dmg inflicted
	actualDmg = (atk - def - armor);

	if (actualDmg > 0)
	{
	strengthPoint = (strengthPoint - actualDmg);
	}

	//flag to stop character from further action
	if (strengthPoint <= 0)
	{
		// recovers Harry Potter and set is strength point to 0
		if (extraLife == true)
		{
			strengthPoint = 20;
			extraLife = false;
		}
		else     // harry potter has no extra life and will remain dead
		{
			alive = false;
		}
	}
}
