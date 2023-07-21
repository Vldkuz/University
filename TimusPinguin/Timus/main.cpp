#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	size_t N, a, d;

	cin >> N;
	cin >> d >> a;

	bool** matrix = new bool* [N];
	bool** end = new bool* [N];

	for (size_t i = 0; i < N; ++i) {
		matrix[i] = new bool[N];
		end[i] = new bool[N];
		size_t SizeOfBytes = sizeof(bool) * N;
		memset(matrix[i], false,SizeOfBytes);
		memset(end[i], false, SizeOfBytes);
	}

	string str;
	size_t i = 0;
	while (i < N)
	{
		std::getline(cin, str);

		if (str == "") continue;

		for (size_t j = 0; j < N; ++j) {
			matrix[i][j] = str[j] == 48 ? 0 : 1;
		}

		++i;
	}

	bool* visited = new bool[N];
	memset(visited, false, N* sizeof(bool));

	stack<size_t> Stack;

	Stack.push(0);
	size_t CountVertex = 0;
	long long int summary = 0;


	while (CountVertex < N) {

		size_t start;
		while (!Stack.empty())
		{
			start = Stack.top();
			++CountVertex;
			Stack.pop();
			visited[start] = true;

			for (size_t j = 0; j < N; ++j)
			{
				if (visited[j] == true)
					continue;

				if (matrix[start][j] == false)
					continue;


				Stack.push(j);
				end[start][j] = 1;
				end[j][start] = 1;

				visited[j] = true;
			}
		}

		if (CountVertex < N)
		{
			size_t i = 1;
			while (visited[i]) {++i;}

			end[start][i] = 1;
			end[i][start] = 1;

			Stack.push(i);
			continue;
		}
	}


	for (size_t i = 0; i < N; ++i)
	{
		for (size_t j = i + 1; j < N; ++j)
		{
			if (matrix[i][j] && !end[i][j]) {
				summary += d;
				continue;
			}

			if (!matrix[i][j] && end[i][j])
			{
				summary += a;
			}
		}
	}

	cout << summary << std::endl;


	for (size_t i = 0; i < N; ++i)
	{
		for (size_t j = 0; j < N; ++j)
		{
			if (matrix[i][j] && !end[i][j]) {
				std::cout << "d";
				continue;
			}

			if (!matrix[i][j] && end[i][j]) {
				std::cout << "a";
				continue;
			}

			std::cout << 0;
		}
		std::cout << std::endl;
	}

	
	return 0;
}