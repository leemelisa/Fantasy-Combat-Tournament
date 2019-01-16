/********************************************************************
** Program Name:    Fantasy Combat Tournament
** Author:          Melisa Lee
** Date:            11/18/2018
** Description:     Medusa.hpp is the class header file. Medusa class
		    is the derived class of the base class Characters.
*********************************************************************/
#ifndef MEDUSA_HPP
#define	MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character
{
	private:

	public:
		Medusa(int, int, string, int);
		int calculateAtk();
		void calculateDef(int);
};

#endif 

