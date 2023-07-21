#pragma once
#include <iostream>

struct Edge
{
	Edge();
	Edge(Edge& OldEdge);

	~Edge();

	int LVertex;
	int RVertex;
	Edge* pNext;
	Edge* pLast;
};


class ClassEdge
{
public:
	~ClassEdge();
	void push(int LVert, int RVert);
	Edge pop();

	friend std::ostream& operator<<(std::ostream& in, ClassEdge& ListEdge);
private:
	Edge* pStart = nullptr;
	Edge* pEnd = nullptr;
};

