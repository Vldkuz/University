#include "LinkedList.h"

LinkedList::LinkedList()
{
	pStart = nullptr;
	pEnd = nullptr;
}

void LinkedList::Add(std::string key, std::string end)
{
	if (key == "") { return;}

	if (pStart == nullptr)
	{
		pStart = new Node();
		pStart->Start = key;
		pStart->WrapperCount.SetCount(end);
		pEnd = pStart;
		return;
	}
	
	Node* pList = pStart;
	while (pList != nullptr)
	{
		if (pList->Start == key) {
			pList->WrapperCount.SetCount(end); return;
		}
		pList = pList->pNext;
	}

	Node* NewNode = new Node();
	NewNode->Start = key;
	NewNode->WrapperCount.SetCount(end);
	pEnd->pNext = NewNode;
	pEnd = NewNode;
}

void LinkedList::ShowList(std::ostream& out)
{
	Node* pList = pStart;
	while (pList != nullptr)
	{
		out << pList->Start << ":" << pList->WrapperCount.End << std::endl;
		pList = pList->pNext;
	}
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

void NodeEnd::SetCount(std::string pEnd)
{
	
	if (count == 0 && End == "") { End = pEnd; }

	if (pEnd == End) { ++count; return; }

	--count;

	if (count == 0) {End > pEnd? End = pEnd : End; ++count; }
}
