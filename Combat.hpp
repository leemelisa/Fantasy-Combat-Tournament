/*********************************************************************
** Program Name:    Fantasy Combat Tournament
** Author:          Melisa Lee
** Date:            11/18/2018
** Description:     Combat.hpp is the Combat class header file. 
*********************************************************************/
#ifndef COMBAT_HPP
#define COMBAT_HPP

#include "Character.hpp"
#include "Queue.hpp"
#include <string>
using std::string;

class Combat
{
	private:
		// linked list for each team and for loser
		Queue team1;
		Queue team2;
		Queue losers;
		// flags
		bool firstTime = true;
		bool exitGame = false;
		bool playAgain = true;
		// counters
		int round = 1;
		int team1Score = 0;
		int team2Score = 0;
		int choice;

	public:
		Combat();
		void fillLineup();
		void startTourny();
		void playAgainMenu();
		void fight();
		void displayResult();
		~Combat();
};

#endif
