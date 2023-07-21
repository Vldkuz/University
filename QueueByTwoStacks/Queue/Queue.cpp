#include "Queue.h"

void Queue::push(double element) {First.push(element);}

double Queue::pop()
{
	while (!First.IsEmpty()) {
		Second.push(First.pop());
	}

	double Value = Second.pop();

	while (!Second.IsEmpty()) {
		First.push(Second.pop());
	}

	return Value;
}

double Queue::front(){return First.front();}
double Queue::back(){return First.back();}

std::ostream& operator<<(std::ostream& out, Queue& MyQueue) {
	out << MyQueue.First;
	return out;
}
