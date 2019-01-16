/*********************************************************************
** Program name:    Fantasy Combat Tournament
** Author:          Melisa Lee
** Date:            11/18/2018
** Description:     Barbarian.hpp is the class header file. Barbarian 
		    class is the derived class of the base class Character.
*********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian: public Character
{
	private:

	public:
		Barbarian(int, int, string, int);
		int calculateAtk();
		void calculateDef(int);
};

#endif 
