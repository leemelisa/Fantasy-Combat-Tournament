/********************************************************************
** Program Name:    Fantasy Combat Tournament
** Author:          Melisa Lee
** Date:            11/18/2018
** Description:     BlueMen.cpp is the BlueMen class function
		    implemenation file.
*********************************************************************/
#include "BlueMen.hpp"

#include <iostream>
using std::endl;
using std::cout;

/*********************************************************************
** Description: This constructor takes in three integers: armorPoint, 
		sp, and chracter type 1 string: chracter's name.
		Set the member variable of BlueMen class.
*********************************************************************/
BlueMen::BlueMen(int armorPoint, int sp, string charName, int type):Character(armorPoint, sp, charName, type)
{

}

/*********************************************************************
** Description: This function accepts no parameter. Calculates and
		return damage attacked by the attacker.
*********************************************************************/
int BlueMen::calculateAtk()
{
	// calculate attacker's roll
	int firstRoll = randomNum(2, 10);
	int secondRoll = randomNum(2, 10);	

	return (firstRoll + secondRoll);
}

/*********************************************************************
** Description: This function accepts a parameter: integer damage
		attack. Calculate the acutal damage inflicted and apply
		the damage to the defender's strength point.
*********************************************************************/
void BlueMen::calculateDef(int atk)
{
	int actualDmg;
	int def;

	// calculate special ability mob
	int numberOfDie = (strengthPoint / 4);
	if (strengthPoint < 4)
	{
		numberOfDie = 1;
	}

	// calculate defender's roll
	if (numberOfDie == 1)
	{
		def = randomNum(1, 6);
	}
	else if (numberOfDie == 2)
	{
		int firstRoll = randomNum(1, 6);
		int secondRoll = randomNum(1, 6);
		def = (firstRoll + secondRoll);
	}
	else
	{
		int firstRoll = randomNum(1, 6);
		int secondRoll = randomNum(1, 6);
		int thirdRoll = randomNum(1, 6);
		def = (firstRoll + secondRoll + thirdRoll);
	}


	// calculate actual dmg inflicted
	actualDmg = (atk - def - armor);

	// apply dmg to defender's strength point
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
