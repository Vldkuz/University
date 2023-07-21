#include "LinkedList.h"

LinkedList::LinkedList()
{
	pStart = nullptr;
	pEnd = nullptr;
}

void LinkedList::Add(std::string key, std::string NextWord)
{
	if (pStart == nullptr)
	{
		Node* NewNode = new Node();
		NewNode->phraseBeginning = key;
		NewNode->NextWords = NextWord;
		pStart = NewNode;
		pEnd = pStart;
		return;
	}

	Node* NewNode = new Node();
	NewNode->phraseBeginning = key;
	NewNode->NextWords = NextWord;
	pEnd->pNext = NewNode;
	pEnd = NewNode;
}

bool LinkedList::IsInList(std::string& key)
{
	Node* pList = pStart;
	while (pList != nullptr)
	{
		if (pList->phraseBeginning == key) {
			key += ' ' + pList->NextWords;
			return true;
		}
		pList = pList->pNext;
	}

	return false;
}

bool LinkedList::IsInListLast(std::string& key)
{
	Node* pList = pStart;
	while (pList != nullptr)
	{
		if (pList->phraseBeginning == key) {
			key = pList->NextWords;
			return true;
		}
		pList = pList->pNext;
	}

	return false;
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
