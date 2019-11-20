#pragma once
class CNode
{
	int number;
public:
	CNode *next;
	CNode();
	CNode(int);
	void print()const;
	void writeToFile(ofstream&);
	void readFromFile(ifstream&);
	void set_Number(int);
	int getNumber()const;
	//~CNode();
};