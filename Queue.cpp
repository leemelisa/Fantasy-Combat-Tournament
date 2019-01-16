/*********************************************************************
** Program name:    Fantasy Combat Tournament
** Author:          Melisa Lee
** Date:            11/18/2018
** Description:     Queue.cpp is the QueueNode class implemenation
		    file.
*********************************************************************/

#include "Queue.hpp"
#include "Menu.hpp"
#include "validate.hpp"
#include "Character.hpp"
#include <iostream>
#include <string>
#include <climits>
using std::string;
using std::cout;
using std::cin;
using std::endl;

/********************************************************************
** Description: This default constructor set the head to null.
********************************************************************/
Queue::Queue()
{
	head = NULL;
}


/********************************************************************
** Description: This function accepts no parameter. Checks if the
		queue is empty. If so, returns true; otherwise,
		return false.
********************************************************************/
bool Queue::isEmpty()
{
	return (head == NULL);
}

/********************************************************************
** Description: This function takes in a chracter type and name
		and place it in a node. Appends it to the back of the 
		list.
********************************************************************/
void Queue::addBack(int type, string charName)
{
	// create node that has userinput value
	QueueNode *nodePtr = new QueueNode(type, charName);

	// single node add head
	if (isEmpty())
	{
		// assign head and set prev and next to itself
		head = nodePtr;
		nodePtr->next = head;
		nodePtr->prev = head;
	}
	else
	{
		// store last node
		QueueNode *newLast = head->prev;
		// make new last node
		nodePtr->prev = newLast;
		nodePtr->next = head;
		// insert node to cicle link
		head->prev = nodePtr;
		newLast->next = nodePtr;
	}
}


/********************************************************************
** Description: This function takes in no parameter. Traverses through
		the queue from head using next pointers, and prints
		the values of each QueueNode in the queue.
********************************************************************/
void Queue::printQueue()
{
	QueueNode *nodePtr = head;

	cout << "Your queue is: ";

	// iterate queue and display values in each node
	if (!isEmpty())
	{
		do
		{
			cout << nodePtr->character->getName() << " ";
			nodePtr = nodePtr->next;
		} while (nodePtr != head);
	}
	// display queue is empty
	else
	{
		cout << "you're queue is empty.\n";
	}
	cout << endl;
}


/********************************************************************
** Description: This function takes in no parameter. Returns a pointer
		to a Character type of the node at the front of the queue.
********************************************************************/
Character* Queue::getFront()
{
	if (isEmpty())
	{
		return NULL;
	}
	else
	{
		return head->character;
	}
}

/********************************************************************
** Description: This function takes in a pointer of node and place the
		node in back of the linked list.
********************************************************************/
void Queue::addBackChar(QueueNode* charNode)
{
	// single node add head
	if (isEmpty())
	{
		// assign head and set prev and next to itself
		head = charNode;
		charNode->next = head;
		charNode->prev = head;
	}
	else
	{
		// store last node
		QueueNode *newLast = head->prev;
		// make new last node
		charNode->prev = newLast;
		charNode->next = head;
		// insert node to cicle link
		head->prev = charNode;
		newLast->next = charNode;
	}
}

/********************************************************************
** Description: This function takes in no parameter. Returns the 
		head of the linked list and set head prev to new head.
********************************************************************/
QueueNode* Queue::removeFrontChar()
{
	// display warning when queue is empty
	if (isEmpty())
	{
		return NULL;
	}
	// delete single node
	else if (head->next == head)
	{
		QueueNode *temp = head;
		head = NULL;
		return temp;
	}
	else
	{
		QueueNode *temp = head;
		// set new head to next node next to head
		QueueNode *newHead = head->next;
		// set last node
		QueueNode *last = head->prev;
		// link new head with last node and assign new head to head
		newHead->prev = last;
		last->next = newHead;
		head = newHead;
		return temp;
	}
}

/********************************************************************
** Description: This functions accepts a pointer of a node and move 
		it to the front of the linked list.
********************************************************************/
void Queue::addFrontChar(QueueNode* charNode)
{
	// single node add head
	if (isEmpty())
	{
		// assign head and set prev and next to itself
		head = charNode;
		charNode->next = head;
		charNode->prev = head;
	}
	
	else
	{
		// set new head
		QueueNode *newHead = charNode;
		// save old head
		QueueNode *oldHead = head;
		// save last 
		QueueNode *last = head->prev;

		// link new head and asign new head to head
		newHead->next = oldHead;
		newHead->prev = last;
		head->prev = newHead;
		last->next = head->prev;
		head = newHead;
	}	
}

/********************************************************************
** Description: This function takes in no parameter. Frees up all the
		nodes from the linked list.
********************************************************************/
void Queue::cleanNodes()
{
	QueueNode *nodePtr = head;

	if (nodePtr != NULL)
	{
		do
		{
			// delete head and assign new head
			QueueNode *temp = nodePtr;
			nodePtr = nodePtr->next;
			delete temp;
		} while (nodePtr != NULL && nodePtr != head);
	}

	head = NULL;
}

/********************************************************************
** Description: This destructor calls the cleanNodes function to free
		up memory space from the linked list.
********************************************************************/
Queue::~Queue()
{
	cleanNodes();
}



