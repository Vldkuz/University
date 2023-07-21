#pragma once
#include <iostream>

struct Node
{
	double Value;
	Node* pNext = nullptr;
	Node* pLast = nullptr;
};

class Stack
{
public:
	Stack();

	friend std::ostream& operator<<(std::ostream& out, Stack& MyStack);

	double front();
	double back();
	bool IsEmpty();
	void push(double value);
	double pop();


	~Stack();
private:
	Node* pStart;
	Node* pEnd;
};

