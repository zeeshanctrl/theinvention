#pragma once
#include"CNode.h"

class CStack
{
	
public:		 
	CNode *top;
	CStack();
	CStack(CNode*&);						//parametarized constuctor
	CStack(const CStack&);					//copy constructor
	CStack& operator=(const CStack&);		//assignment operator
	CStack &push(CNode*&);
	CNode *pop();
	//pre_condition based actions
	bool isNotEmpty()const;
	void writeStackToFile(ofstream&);
	void readStackFromFile(ifstream&);
	bool isEmpty()const;
	void printTop()const;
	void print_Stack()const;
	void interFace()const;
	~CStack();
};

