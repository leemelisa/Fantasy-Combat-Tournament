/**********************************************************************
** Program Name:    Fantasy Combat Tournament
** Author:          Melisa Lee
** Date:            11/18/2018
** Description:     Combat.cpp is the Combat class function implemenation
		    file.
*********************************************************************/
#include "Combat.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Menu.hpp"
#include "validate.hpp"
#include "QueueNode.hpp"

#include <iostream>
#include <string>
#include <climits>
using std::endl;
using std::cin;
using std::cout;
using std::string;

/*********************************************************************
** Description: Default constructor.
*********************************************************************/
Combat::Combat()
{

}

/*********************************************************************
** Description: This function accepts no parameter. Display menu to the
		user. Create a character for each player and each player's
		character will fight until one dies. Create team linked list.
*********************************************************************/
void Combat::fillLineup()
{
	Menu welcomeMenu;
	string input;
	string charName;
	int charChoice;
	int team1Size;
	int team2Size;

	// if user first time display first menu
	if (firstTime)
	{
		welcomeMenu.addOption("1. Play");
		welcomeMenu.addOption("2. Exit");
		welcomeMenu.printOptions();
		firstTime = false;
		choice = welcomeMenu.getUserChoice();
	}

	// iterate until user wants to quit
	if (choice == 1 && playAgain == true)
	{
		// ask user for number of fighters for each team
		cout << "Enter how many fighters for team 1: ";
		cin >> input;
		team1Size = validate(input, 1, INT_MAX);
		cout << "Enter how many fighters for team 2: ";
		cin >> input;
		team2Size = validate(input, 1, INT_MAX);
		cout << endl;

		// display option and instructions to user
		cout << "\n------------------------------------------------\n"
			<< "\tInstuctions:\n"
			<< "------------------------------------------------\n"
			<< "Choose the type of character, and enter a name for the fighter.\n"
			<< "1. Vampire\n"
			<< "2. Barbarian\n"
			<< "3. Blue Men\n"
			<< "4. Medusa\n"
			<< "5. Harry Potter\n"
			<< "\nTeam 1 please enter your line up\n"
			"------------------------------------------------\n";

		// iterate to fill team 1 line up
		for (int i = 0; i < team1Size; i++)
		{
			cout << "\tFighter " << (i + 1) << endl;
			cout << "Enter fighter chracter type: ";
			cin >> input;
			charChoice = validate(input, 1, 5);
			cout << "Enter name for fighter: ";
			cin.ignore();
			getline(cin, charName);
			team1.addBack(charChoice, charName);
		}

		cout << "\n\nTeam 2 please enter your line up\n"
		<< "------------------------------------------------\n";

		// iterate to fill team 1 line up
		for (int i = 0; i < team2Size; i++)
		{
			cout << "\tFighter " << (i + 1) << endl;
			cout << "Enter fighter chracter type: ";
			cin >> input;
			charChoice = validate(input, 1, 5);
			cout << "Enter name for fighter: ";
			cin.ignore();
			getline(cin, charName);
			team2.addBack(charChoice, charName);
		}

		// start the tournament
		startTourny();
	}
	else
	{
		cout << "Good-bye!" << endl;
	}
}

/*********************************************************************
** Description: This function accepts no parameter. Allows each head
		fighter fight until one team has no more fighters. 
		Maintains linked list.
*********************************************************************/
void Combat::startTourny()
{
	// iterate until one team is dies
	while (team1.getFront() != NULL && team2.getFront() != NULL)
	{

		// display results
		cout << "\n\n------------------------------------------------\n";
		cout << "\t\tRound " << round << endl;
		cout << "------------------------------------------------\n";

		// display type of character and name per team
		cout << "Team 1: "; 
		cout << team1.getFront()->getCharType() << ", ";
		cout << team1.getFront()->getName() << " vs.";
		cout << "Team 2: ";
		cout << team2.getFront()->getCharType() << ", ";
		cout << team2.getFront()->getName() << "\n";

		//iterate until someone dies
		while ((team1.getFront()->getAlive()) && (team2.getFront()->getAlive() && playAgain))
		{
			fight();
		}

		// if team 1 fighter lost remove and put in loser 
		if (team1.getFront()->getAlive() == false)
		{
			team2Score++;
			losers.addFrontChar(team1.removeFrontChar());
		}
		// if team 1 winner add to the end of que and recover some hp
		else if (team1.getFront()->getAlive() == true)
		{
			team1.getFront()->recovery();
			team1.addBackChar(team1.removeFrontChar());
		}
		// if team 2 fighter lost remove and put in loser 
		if (team2.getFront()->getAlive() == false)
		{
			team1Score++;
			losers.addFrontChar(team2.removeFrontChar());
		}
		// if team 2 winner add to the end of que and recover some hp
		else if (team2.getFront()->getAlive() == true)
		{
			team2.getFront()->recovery();
			team2.addBackChar(team2.removeFrontChar());
		}

		// display scores to user
		cout << "\nScore" << endl;
		cout << "Team 1: " << team1Score << endl;
		cout << "Team 2: " << team2Score << endl;

		round++;
	}

	displayResult();
}

/*********************************************************************
** Description: This function accepts no parameter. Display the score 
		to the user and ask if the user wants to view the loser
		pile. In addition, ask if the user wants to play again.
*********************************************************************/
void Combat::displayResult()
{
	string input;

	// display results
	cout << "\n------------------------------------------------\n";
	cout << "\t\tResults\n";
	cout << "------------------------------------------------\n";
	cout << "Team 1 Score: " << team1Score << endl;
	cout << "Team 2 Score: " << team2Score << endl;

	// display winner
	if (team1Score > team2Score)
	{
		cout << "\nTeam 1 won!\n";
	}
	else if (team1Score < team2Score)
	{
		cout << "\nTeam 2 won!\n";
	}
	else
	{
		cout << "\nIt's a tie!\n";
	}

	// ask if user want to display loser pile
	cout << "\n------------------------------------------------\n";
	cout << "\tDisplay content of loser pile?\n";
	cout << "------------------------------------------------\n";
	cout << "1. Yes\n";
	cout << "2. No\n";
	cout << "Enter your choice: ";
	cin >> input;
	// validate user choice and print loser pile
	if (validate(input, 1, 2) == 1)
	{
		cout << "\nLoser pile\n";
		losers.printQueue();
	}

	playAgainMenu();
}

/*********************************************************************
** Description: This function accepts no parameter. Begins the combat
		between attacker and defender.
*********************************************************************/
void Combat::fight()
{
	//if player 1 is alive attack
	if (team1.getFront()->getAlive())
	{
		//calculates p2 defense take in player 1 atack
		team1.getFront()->calculateDef(team1.getFront()->calculateAtk());
	}
	//if player 2 is alive attack
	if (team2.getFront()->getAlive())
	{
		//calculates p1 defense take in player 2 atack
		team2.getFront()->calculateDef(team2.getFront()->calculateAtk());
	}
}


/*********************************************************************
** Description: This function accepts no parameter and display a
		play again menu to the user.
*********************************************************************/
void Combat::playAgainMenu()
{
	string userInput;
	
	// display play agian menu to user
	cout << "\n------------------------------------------------\n";
	cout << "\tWould you like to play again?\n";
	cout << "------------------------------------------------\n";
	cout << "1. Play again\n";
	cout << "2. Exit\n";
	cout << "Enter your choice: ";
	cin >> userInput;

	// validate user input and play again
	if (validate(userInput, 1, 2) == 1)
	{
		// reset round counter
		round = 1;
		// reset score counter
		team1Score = 0;
		team2Score = 0;
		// clear all line ups
		team1.cleanNodes();
		team2.cleanNodes();
		losers.cleanNodes();

		fillLineup();
	}
	// display farewell message to user
	else
	{
		cout << "Good-bye!\n";
		playAgain = false;
	}
}

/*********************************************************************
** Description: This destructor clean each linked list: team1, team2
		and loser.
*********************************************************************/
Combat::~Combat()
{
	team1.cleanNodes();
	team2.cleanNodes();
	losers.cleanNodes();
}
