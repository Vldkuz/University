#include "LinkedList.h"

Node* LinkedList::getStart()
{
	return pStart;
}

LinkedList::LinkedList(const LinkedList& List)
{
	pStart = pEnd = nullptr;
	Node* pList = List.pStart;
	while (pList != nullptr)
	{
		Add(pList->Scalar);
		pList = pList->pNext;
	}
}

LinkedList::LinkedList()
{
	pStart = pEnd = nullptr;
}

void LinkedList::Add(MatrixScalar& Scalar)
{
	Node* NewNode = new Node();
	NewNode->Scalar = Scalar;

	if (pStart == nullptr)
	{
		pStart = NewNode;
		pEnd = pStart;
		return;
	}

	pEnd->pNext = NewNode;
	pEnd = NewNode;
}

LinkedList::~LinkedList()
{
	Node* pList = pStart;
	while (pList != nullptr)
	{
		Node* OldNode = pList;
		pList = pList->pNext;
		delete OldNode;
	}
}
