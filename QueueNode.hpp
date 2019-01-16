/*********************************************************************
** Program name:    Fantasy Combat Tournament
** Author:          Melisa Lee
** Date:            11/8/2018
** Description:     QueueNode.hpp is the QueueNode class header file.
*********************************************************************/

#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

struct QueueNode
{
	QueueNode *next;
	QueueNode *prev;
	Character *character;

	// consturctor create character of the apporimate character type
	QueueNode(int type, string charName)
	{
		if (type == 1)
		{
			character = new Vampire(1, 18, charName, type);
		}
		else if (type == 2)
		{
			character = new Barbarian(0, 12, charName, type);
		}
		else if (type == 3)
		{
			character = new BlueMen(3, 12, charName, type);
		}
		else if (type == 4)
		{
			character = new Medusa(3, 8, charName, type);
		}
		else if (type == 5)
		{
			character = new HarryPotter(0, 10, charName, type);
		}
	}

	// destructor: delete character
	~QueueNode()
	{
		delete character;
	}
};
#endif
