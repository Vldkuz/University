//1. √раф задан списками смежных вершин. —формировать список его ребер.
#include <fstream>
#include <string>
#include "ClassEdge.h"

int main()
{
	std::ifstream file("in.txt");
	std::string MainVertex;
	std::string SideVertex;
	ClassEdge ListEdges;

	while (!file.eof())
	{
		file >> SideVertex;

		if (SideVertex.find(":") != SideVertex.npos)
		{
			MainVertex = SideVertex;
			SideVertex.clear();
			continue;
		}

		ListEdges.push(std::stoi(MainVertex.substr(0,MainVertex.length() - 1)), std::stoi(SideVertex));
	}

	std::cout << ListEdges;


	return 0;
}



