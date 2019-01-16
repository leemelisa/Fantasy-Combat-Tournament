/**********************************************************************
** Program Name:    Fantasy Combat Tournament
** Author:          Melisa Lee
** Date:            11/18/2018
** Description:     HarryPotter.hpp is the class header file. HarryPotter 
		    class is the derived class of the base class Characters.
*********************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"

class HarryPotter : public Character
{
	private:

	public:
		HarryPotter(int, int, string, int);
		int calculateAtk();
		void calculateDef(int);
};

#endif 

