/*********************************************************************
** Program name:    Fantasy Combat Tournament
** Author:          Melisa Lee
** Date:            11/18/2018
** Description:     Vampire.hpp is the class header file. Vampire class 
		    is the derived class of the base class Characters.
*********************************************************************/

#ifndef VAMPIRE_HPP
#define	VAMPIRE_HPP
#include "Character.hpp"

class Vampire: public Character
{
	private:
	public:
		Vampire(int, int, string, int);
		int calculateAtk();
		void calculateDef(int);
};

#endif 

