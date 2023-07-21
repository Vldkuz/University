#include "Queue.h"
#include "Stack.h"
#include "ArrayList.h"

void SomeFunction(int i)
{
	std::cout << i << std::endl;
}

// матрица инцидентности
void BFS2(int** graph, const int n, const int m, int(*goalFunction)(int))
{
	Queue queue;
	bool* visited = new bool[n];


	while (queue.IsEmpty())
	{
		int start = queue.pop();

		goalFunction(start);

		for (int i = 0; i < m; ++i)
		{
			int e = graph[start][i];

			if (e == 0)
				continue;

			int j;
			for (j = 0; j < n; ++j)
			{
				if (j != start && graph[i][j] != 0)
					break;
			}

			if (visited[j] == true)
				continue;

			visited[j] = true;
			queue.push(j);
		}
	}

}
void DFSInternal(int** graph, const int n, int v, bool* visited, int (*goalFunction) (int))
{
}

void DFS(int** graph, const int n,int v,bool* visited, int (*goalFunction)(int))
{
	visited[0] = true;

	int start = 0;

	visited[start] = true;
	goalFunction(start);

	for (int i = 0; i < n; ++i)
	{
		int end = graph[start][i];
		if (end == 0)
			continue;

		if (visited[i] == true)
			continue;

		visited[i] = true;
		DFSInternal(graph, n, i, visited, goalFunction);
	}
}


void BFS(int** graph, const int n, int (*goalFunction)(int))
{
	bool* visited = new bool[n];
	Queue queue;
	queue.push(0);

	while (queue.IsEmpty())
	{
		int start = queue.pop();
		visited[start] = true;
		goalFunction(start);

		for (int i = 0; i < n; ++i)
		{
			int end = graph[start][i];
			if (end == 0)
				continue;

			if (visited[i] == true)
				continue;

			
			//if (!queue.Contains())//Ёквивалентно предыдущему 
			visited[i] = true;
		}
	}
}

void BFS1(int** graph, const int n, int (*goalFunction) (int))
{
	bool* visited = new bool[n] {false};

}

void BFSInternal(int** graph, const int n, int v, bool* visited, int (*goalFunction)(int))
{
	visited[v] = true;
	int start = 0;

	for (int i = 0; i < n; ++i)
	{
		int end = graph[start][i];
		if (end == 0)
			continue;

		if (visited[i] == true)
			continue;


		//if (!queue.Contains())//Ёквивалентно предыдущему 
		visited[i] = true;
		BFSInternal(graph, n, i, visited, goalFunction);
	}
}

//матрица смежности
void TopologicalSort(int** graph, const int n) // способ перенумеровани€ вершин // ѕодумать 
{
	SortedArr list;
	Stack stack;

}

int* Dijkstra(int** graph, const int n, const int start)
{
	bool* visited = new bool[n] {false};
	int* distance = new int[n] {INT_MAX};
	distance[start] = 0;

	for (int j = 0; j < n; ++j)
	{
		int u;
		int min = INT_MAX;
		for (int i = 0; i < n; ++i)
		{
			if (visited[i] != true && distance[i] < min)
			{
				u = i;
				min = distance[i];
			}
		}

		visited[u] = true;
		for (int i = 0; i < n; ++i)
		{
			if (graph[u][i] == 0)
				continue;

			if (visited[i] == true)
				continue;

			int newDistance = distance[u] + graph[u][i];
			if (newDistance < distance[i])
			{
				distance[i] = newDistance;
			}

		}
	}

	return distance;
}


int main()
{

	return 0;
}