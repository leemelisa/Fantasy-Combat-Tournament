/*********************************************************************
** Program name:    Fantasy Combat Tournament
** Author:          Melisa Lee
** Date:            11/18/2018
** Description:     Menu.hpp is the function Menu header file.
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include<string>
#include <vector>
using std::string;
using std::vector;

class Menu
{
	private:
		vector <string> libary;
		int userChoice;

	public:
		void addOption(string);
		void printOptions();
		void setUserOption();
		int getUserChoice();
		void displayHeader(string);
};

#endif
