#include<iostream>
using namespace std;
#include<fstream>
#include "CStack.h"

CStack::CStack() { top = NULL; }
CStack::CStack(CNode *&ptr) {
	top = ptr;
	top->next = NULL;
}
CStack::CStack(const CStack& src) {
	top = src.top;
	if (src.top) {
		CNode* dptr;
		dptr = top = new CNode(*src.top);
		CNode* sptr = src.top->next;
		while (sptr) {
			dptr->next = new CNode(*sptr);
			dptr = dptr->next;
			sptr = sptr->next;
		}
	}
}
//s2 = s1
CStack& CStack::operator=(const CStack& src) {
	if (this == &src) { return *this; }
	if (true) {
		CStack temp;
		temp.top = top;
	}
	if (true) {
		CStack temp = src;
		top = temp.top;
		temp.top = NULL;
	}
	return *this;
}
CStack& CStack::push(CNode *&ptr) {
	ptr->next = top;
	top = ptr;
	ptr = NULL;
	return *this;
}
CNode* CStack::pop() {
	CNode *ptr;
	ptr = top;
	if (top)
	{
		top = top->next;
		ptr->next = NULL;
	}
	return ptr;
}

bool CStack::isNotEmpty()const {
	if (top) { return true; }
	else { return false; }
}
bool CStack::isEmpty()const {
	if (top) { return false; }
	else { return true; }
}
void CStack::printTop()const {
	cout << "value: ";
	top->print();
	cout << endl;
}
void CStack::print_Stack()const {
	CNode* ptr = this->top;
	while (ptr)
	{
		ptr->print(); cout << endl;
		ptr = ptr->next;
	}
	
}
void CStack::writeStackToFile(ofstream& ofs) {
	CStack tmp1 = *this, tmp2;
	CNode* ptr;
	while (tmp1.top)
	{
		ptr = tmp1.pop();
		tmp2.push(ptr);
	}
	ptr = tmp2.top;
	int n = 0;
	while (ptr)
	{
		n = ptr->getNumber();
		ofs.write((char*)&n, sizeof(int));
		ptr = ptr->next;
	}
}
void CStack::readStackFromFile(ifstream& ifs) {
	this->top = NULL;
	CNode* ptr;
	int n = 0;
	while (ifs.read((char*)&n, sizeof(int)))
	{
		ptr = new CNode(n);
		this->push(ptr);
	}
}
void CStack::interFace()const {
	CStack st;
	ifstream ifs("StackFile.txt", ios::binary | ios::in);
	st.readStackFromFile(ifs);
	ifs.close();
	int n = 0;
	cout << "\n\n\t\t____________________________\n";
	cout << "\t\t  Welcome to CStack class\n";
	cout << "\t\t____________________________\n\n";
	cout << "\tPlease enter your choice:\n";
	cout << "\t\t> 1. Push a node\n";
	cout << "\t\t> 2. Pop a node\n";
	cout << "\t\t> 3. Print_Stack \n";
	cout << "\t\t> 4. Print top_Node\n";
	cout << "\t\t> 5. Exit \n\n";
	CNode *ptr = new CNode(0);
	while (true)
	{
		cout << "Your choice: ";
		cin >> n;
		switch (n) {
		case 1: {
			int	i = 0; cout << "Enter value: "; cin >> i;
			ptr = new CNode(i);
			st.push(ptr);
			cout << "\tValue pushed to stack....!!!\n";
			{
				//file Handling
				ofstream file("StackFile.txt", ios::binary | ios::app);	//beg
				st.top->writeToFile(file);
				file.close();
				//end of file Handling
			}
			break;
		}
		case 2:
		{
			if (st.isNotEmpty()) {
				st.pop();
				cout << "\tValue popped from stack.....!!!\n";
				ofstream ofs1("StackFile.txt", ios::binary | ios::out);
				st.writeStackToFile(ofs1);
				ofs1.close();
			}
			else {
				cout << "\t\a\aStack is empty.......!!!\n";
			}
			break;
		}
		case 3:		//to print all nodes of stack from top to bottom
		{
			if (st.isNotEmpty()) { cout << "Stack: \n"; st.print_Stack(); }
			else { cout << "\t\a\aStack is empty.\n"; }
			break;
		}
		case 4:
		{
			if (st.top) {
				st.printTop();
			}
			else {
				cout << "\t\a\aStack is empty.......!!!\n";
			}
			break;
		}
		case 5:
			exit(1);
		default:
		{
			cout << "\t\aInvalid_choice......!!!\n" << endl;
			break;
		}
		}
	}
}
CStack::~CStack() {
	CNode *dptr = top;
	while (top) {
		top = top->next;
		delete dptr;
		dptr = top;
	}
}