#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include "CNode.h"

CNode::CNode()
{
	this->number = 0;
}
CNode::CNode(int no) {
	this->number = no;
}
void CNode::print()const {
	cout << this->number;
}
void CNode::writeToFile(ofstream& OFile) {
	OFile.write((char*)&number, sizeof(number));
}
void CNode::readFromFile(ifstream& IFile) {
	IFile.read((char*)&number, sizeof(number));
}
void CNode::set_Number(int no) {
	this->number = no;
}
int CNode::getNumber()const {
	return this->number;
}