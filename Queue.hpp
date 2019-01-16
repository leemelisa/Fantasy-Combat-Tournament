/*********************************************************************
** Program name:    Fantasy Combat Tournament
** Author:          Melisa Lee
** Date:            11/8/2018
** Description:     Queue.hpp is the Queue class header file.
*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "QueueNode.hpp"

class Queue
{
	private:
		QueueNode *head;  // points to first QueueNode in queue
	public:
		Queue();
		bool isEmpty();
		void addBack(int, string);
		void printQueue();
		void addBackChar(QueueNode*);
		void addFrontChar(QueueNode*);
		void cleanNodes();
		QueueNode* removeFrontChar();
		Character* getFront();

		~Queue();

	
};
#endif
