/*********************************************************************
** Program name:    Fantasy Combat Tournament
** Author:          Melisa Lee
** Date:            11/18/2018
** Description:     BlueMen.hpp is the class header file. BlueMen class
		    is the derived class of the base class Character.
*********************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Character.hpp"

class BlueMen: public Character
{
	private:

	public:
		BlueMen(int, int, string, int);
		int calculateAtk();
		void calculateDef(int);
};
#endif

