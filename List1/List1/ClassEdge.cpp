#include "ClassEdge.h"

ClassEdge::~ClassEdge()
{
	Edge* pNode = pStart;
	while (pNode != nullptr)
	{
		Edge* OldNode = pNode;
		pNode = pNode->pNext;

		delete OldNode;
	}
}

void ClassEdge::push(int LVert,int RVert)
{
	Edge* NewNode = new Edge();
	NewNode->LVertex = LVert;
	NewNode->RVertex = RVert;

	if (pStart == nullptr)
	{
		pStart = pEnd = NewNode;
		return;}

	pEnd->pNext = NewNode;
	NewNode->pLast = pEnd;
	pEnd = NewNode;
}

Edge ClassEdge::pop()
{
	Edge* pLast = pEnd;
	pLast->pLast = nullptr;

	pEnd = pEnd->pLast;
	return *pLast;
}

Edge::Edge() {pNext = pLast = nullptr;}

Edge::Edge(Edge& OldEdge)
{
	LVertex = OldEdge.LVertex;
	RVertex = OldEdge.RVertex;
	pNext = OldEdge.pNext;
	pLast = OldEdge.pLast;}

Edge::~Edge()
{
	pNext = nullptr;
	pLast = nullptr;
}

std::ostream& operator<<(std::ostream& in, ClassEdge& ListEdge)
{
	Edge* pNode = ListEdge.pStart;

	while (pNode != nullptr)
	{
		in << pNode->LVertex << ":" << pNode->RVertex << std::endl;
		pNode = pNode->pNext;
	}

	return in;
}
