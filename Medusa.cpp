/*********************************************************************
** Program Name:    Fantasy Combat Tournament
** Author:          Melisa Lee
** Date:            11/18/2018
** Description:     Medusa.cpp is the Medusa class function
		    implemenation file.
*********************************************************************/
#include "Medusa.hpp"

#include <iostream>
using std::endl;
using std::cout;

/*********************************************************************
** Description: This constructor takes in three integers: armorPoint and
		sp and type; one string: character name. Set the member 
		variable of Medusa class.
*********************************************************************/
Medusa::Medusa(int armorPoint, int sp, string charName, int type) :Character(armorPoint, sp, charName, type)
{

}

/*********************************************************************
** Description: This function accepts no parameter. Calculates and
		return damage attacked by the attacker.
*********************************************************************/
int Medusa::calculateAtk()
{
	int total;
	int firstRoll = randomNum(1, 6);
	int secondRoll = randomNum(1, 6);

	total = (firstRoll + secondRoll);

	// activate medusa special ability if she rolls a 12
	if (total == 12)
	{
		total = 999;
	}

	return total;
}

/*********************************************************************
** Description: This function accepts a parameter: integer damage
		attack. Calculate the acutal damage inflicted and apply
		the damage to the defender's strength point.
*********************************************************************/
void Medusa::calculateDef(int atk)
{
	int actualDmg;
	int def = randomNum(1, 6);	//calculate defender's roll

	//calculate actual dmg inflicted
	actualDmg = (atk - def - armor);

	//apply dmg to defender's strength point
	if (actualDmg > 0)
	{
		strengthPoint = (strengthPoint - actualDmg);
	}

	//flag to character to stop further actions
	if (strengthPoint <= 0)
	{
		alive = false;
	}
}
