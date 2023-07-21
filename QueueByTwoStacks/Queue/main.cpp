#include "Queue.h"

int main()
{
	Queue MyQueue;
	for (int i = 0; i < 10; ++i)
	{
		MyQueue.push(i);
	}

	std::cout << MyQueue << std::endl;
	MyQueue.pop();
	std::cout << MyQueue;

	return 0;
}