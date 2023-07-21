#pragma once
#include "Stack.h"
#include <iostream>

class Queue
{
public:
	friend std::ostream& operator<<(std::ostream& out, Queue& MyQueue);

	void push(double element);
	double pop();
	double front();
	double back();
private:
	Stack First;
	Stack Second;
};

