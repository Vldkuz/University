#include <iostream>

struct Road
{
	Road() {};
	Road(double& MaxSpeed, double& Distance) {Time = Distance / MaxSpeed;};

	friend std::istream& operator>>(std::istream& in, Road& ThisRoad) 
	{
		double dist, maxspeed;
		in >> dist >> maxspeed;

		ThisRoad.Time = dist / maxspeed;
		return in;
	}

	double Time;
};


int main()
{
	size_t N;
	std::cin >> N;
	Road** matrix = new Road* [N];
	for (size_t i = 0; i < N; ++i) {matrix[i] = new Road[N];}

	for (size_t i = 0; i < N; ++i)
	{
		for (size_t j = 0; j < N; ++j)
		{
			std::cin >> matrix[i][j];
		}
	}
	size_t start;
	std::cin >> start;

	bool* visited = new bool[N] {false};
	double* distance = new double[N] { std::numeric_limits<double>::max()};
	distance[start] = 0;

	for (int j = 0; j < N; ++j)
	{
		int u;
		double min = std::numeric_limits<double>::max();

		for (int i = 0; i < N; ++i)
		{
			if (visited[i] != true && distance[i] < min)
			{
				u = i;
				min = distance[i];
			}
		}

		visited[u] = true;
		for (int i = 0; i < N; ++i)
		{
			if (matrix[u][i].Time == 0)
				continue;
			
			if (visited[i] == true)
				continue;

			double NewDistance = distance[u] + matrix[u][i].Time;
			if (NewDistance < distance[i]) {distance[i] = NewDistance;}
		}
	}

	double MaxTime = distance[0];
	for (int i = 1; i < N; ++i)
	{
		if (MaxTime < distance[i]) {
			MaxTime = distance[i];
		}

	}
	
	std::cout << MaxTime << std::endl;
	return 0;
}

