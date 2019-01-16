/*********************************************************************
** Program name:    Fantasy Combat Tournament
** Author:          Melisa Lee
** Date:            11/18/2018
** Description:     Vampire.cpp is the Vampire class function
		    implemenation file.
*********************************************************************/

#include "Vampire.hpp"

#include <iostream>
using std::endl;
using std::cout;

/*********************************************************************
** Description: This constructor takes in three integers: armorPoint,
		sp and type; one string: character name. Set the 
		member variable of Vampire class.
*********************************************************************/
Vampire::Vampire(int armorPoint, int sp, string charName, int type) :Character(armorPoint, sp, charName, type)
{

}

/*********************************************************************
** Description: This function accepts no parameter. Calculates and
		return damage attacked by the attacker.
*********************************************************************/
int Vampire::calculateAtk()
{
	int roll = randomNum(1, 6);		// calculate attacker's roll

	return roll;
}

/*********************************************************************
** Description: This function accepts a parameter: integer damage
		attack. Calculate the acutal damage inflicted and apply
		the damage to the defender's strength point.
*********************************************************************/
void Vampire::calculateDef(int atk)
{
	int actualDmg;
	int def = randomNum(1, 6);	// calculate defender's roll
	int charm = randomNum(1, 2);	// special ability chance
	
	// opponent attack successed 
	if (charm == 2)
	{
		//Calculate and display actual dmg inflicted
		actualDmg = (atk - def - armor);

	
		//apply dmg to defender's strength point
		if (actualDmg > 0)
		{
			strengthPoint = (strengthPoint - actualDmg);
		}

		//flag character from further actions
		if (strengthPoint <= 0)
		{
			alive = false;
		}
	}
}
