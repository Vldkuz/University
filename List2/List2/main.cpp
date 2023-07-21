#include <iostream>
#include "Queue.h"
#include <fstream>

int main()
{
	std::ifstream file("In.txt");

	size_t Size;
	file >> Size;

	int** Matrix = new int* [Size];
	for (int i = 0; i < Size; ++i) { Matrix[i] = new int[Size]; }
	for (int i = 0; i < Size; ++i) { for (int j = 0; j < Size; ++j) { file >> Matrix[i][j]; } }

	bool* visited = new bool[Size] {false};
	Queue<int> queue;
	Queue<int> Stack;


	int* Linked = new int[Size] {-1};
	size_t k = 0;

	queue.push(0);
	while (!queue.IsEmpty())
	{
		int start = queue.pop();
		Stack.push(start);
		visited[start] = true;

		for (int i = 0; i < Size; ++i)
		{
			int end = Matrix[start][i];

			if (end == 0)
				continue;

			if (visited[i] == true)
				continue;


			queue.push(i);
			visited[i] = true;
		}
	}

	std::cout << "First Linked Comp: ";
	std::cout << Stack;
	std::cout << std::endl;
	for (int i = 0; i < Size; ++i)
	{
		if (!visited[i])
			std::cout << i << std::endl;
	}

	return 0;
}