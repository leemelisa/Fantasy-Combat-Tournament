/*********************************************************************
** Program name:    Fantasy Combat Tournament
** Author:          Melisa Lee
** Date:            11/18/2018
** Description:     Menu.cpp is the Menu class function implemenation
		    file.
*********************************************************************/

#include "Menu.hpp"
#include "validate.hpp"
#include <climits>
#include <iostream>
using std::endl;
using std::cin;
using std::cout;

/********************************************************************
** Description: This function accepts a string input and store the
		string at the end of a vector.
********************************************************************/
void Menu::addOption(string input)
{
	libary.push_back(input);
}

/********************************************************************
** Description: This function accepts no parameter and prints out the
		Menu to the user.
********************************************************************/
void Menu::printOptions()
{
	cout << "------------------------------------------------\n"
		<< "\t\tMenu\n"
		<< "------------------------------------------------\n";
	for (int i = 0; i < libary.size(); i++)
	{
		cout << libary[i] << endl;
	}

	setUserOption();
}

/*******************************************************************
** Description: This function accepts no parameter. Ask, validate
		and store user choice.
*******************************************************************/
void Menu::setUserOption()
{
	string input;

	cout << "\nEnter your choice: ";
	cin >> input;
	userChoice = validate(input, 1, 2);
}

/*******************************************************************
** Description: This function accepts no parameter and returns the
		users choice as an integer.
*******************************************************************/
int Menu::getUserChoice()
{
	return userChoice;
}


/*******************************************************************
** Description: This function accepts a header as a string. Display 
		welcome header to the user.
*******************************************************************/
void Menu::displayHeader(string header)
{
	cout << "\t" << header << "\n";
}
