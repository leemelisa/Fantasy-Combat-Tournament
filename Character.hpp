/*********************************************************************
** Program name:    Fantasy Combat Tournament
** Author:          Melisa Lee
** Date:            11/18/2018
** Description:     Character.hpp is the function validate header file.
		    This is the base class for all dervied classes.
*********************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
using std::string;

class Character
{
	protected:
		int armor;
		int strengthPoint;
		int startingSP;
		int charType;
		string name;
		// flags
		bool alive = true;	
		bool extraLife = true;	

	public:
		Character();
		Character(int, int, string, int);
		//pure virtual functions only need to declared
		virtual int calculateAtk() = 0;
		virtual void calculateDef(int) = 0;
		int getArmor();
		int getSP();
		string getName();
		string getCharType();
		bool getAlive();
		int randomNum(int, int);
		void recovery();
};

#endif
