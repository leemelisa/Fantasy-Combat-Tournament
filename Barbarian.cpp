/**********************************************************************
** Program Name:    Fantasy Combat Tournament
** Author:          Melisa Lee
** Date:            11/18/2018
** Description:     Barbarian.cpp is the Barbarian class function
		    implemenation file.
*********************************************************************/
#include "Barbarian.hpp"

#include <iostream>
using std::endl;
using std::cout;

/*********************************************************************
** Description: This constructor takes in three integers: armorPoint,
		strength point, and character type one string: 
		character's name and set the member variable of 
		Barbarian class.
*********************************************************************/
Barbarian::Barbarian(int armorPoint, int sp, string charName, int type):Character(armorPoint, sp, charName, type)
{

}

/*********************************************************************
** Description: This function accepts no parameter. Calculates and 
		return damage attacked by the attacker.
*********************************************************************/
int Barbarian::calculateAtk()
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
void Barbarian::calculateDef(int atk)
{
	int actualDmg;
	int def;
	// calculate defender's roll
	int firstRoll = randomNum(1, 6);
	int secondRoll = randomNum(1, 6);

	def = (firstRoll + secondRoll);


	//calculate and display actual dmg inflicted
	actualDmg = (atk - def - armor);


	//apply dmg to defender's strength point
	if (actualDmg > 0)
	{
		strengthPoint = (strengthPoint - actualDmg);
	}

	// flag to stop character from attacking or defending
	if (strengthPoint <= 0)
	{
		alive = false;
	}
}
