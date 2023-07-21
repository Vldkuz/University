#include "ClassPolynom.h"
#include <iostream>

Polynom::Polynom()
{
	pStart = nullptr;
	pEnd = nullptr;
}

Polynom::Polynom(Polynom& d1)
{ 

}

void Polynom::add(double factor)
{
	if (pStart == nullptr)
	{
		pStart = new Node();
		pStart->degree = 0;
		pStart->factor = factor;
		pEnd = pStart;
		return;
	}

	Node* NewNode = new Node();
	NewNode->degree = ++max_degree;
	NewNode->factor = factor;
	pEnd->pNext = NewNode;
	pEnd = NewNode;
}

Polynom* Polynom::operator+(Polynom& d1)
{
	Node* pList_1 = pStart;
	Node* pList_2 = d1.pStart;
	Polynom* summary = new Polynom();
	while (pList_1 != nullptr && pList_2 != nullptr)
	{
		summary->add(pList_1->factor + pList_2->factor);
		pList_1 = pList_1->pNext;
		pList_2 = pList_2->pNext;
	}

	if (pList_1 == nullptr)
	{
		while (pList_2 != nullptr)
		{
			summary->add(pList_2->factor);
			pList_2 = pList_2->pNext;
		}
	}

	if (pList_2 == nullptr)
	{
		while (pList_1 != nullptr)
		{
			summary->add(pList_1->factor);
			pList_1 = pList_1->pNext;
		}
	}

	return summary;
}

Polynom* Polynom::operator*(Polynom& d1)
{
	Polynom* tmp = new Polynom();

	size_t maxdeg = max_degree + d1.max_degree;
	size_t k = 0;

	while (k <= maxdeg)
	{
		tmp->add(0);
		++k;
	}

	Node* pList_1 = d1.pStart;
	while (pList_1 != nullptr)
	{
		Node* pList_2 = pStart;
		while (pList_2 != nullptr)
		{
			Node* pCurrent = tmp->pStart;
			while (pCurrent != nullptr)
			{
				if ((pList_1->degree + pList_2->degree) == pCurrent->degree)
				{
					pCurrent->factor += pList_1->factor * pList_2->factor;
				}

				pCurrent = pCurrent->pNext;
			}
			pList_2 = pList_2->pNext;
		}
		pList_1 = pList_1->pNext;
	}

	return tmp;
}

void Polynom::ShowPolynom()
{
	Node* pList = pStart;

	while (pList != nullptr)
	{
		std::cout << pList->factor << " ";
		pList = pList->pNext;
	}
	std::cout << std::endl;
}




Polynom::~Polynom()
{
	Node* pList = pStart;
	while (pList != nullptr)
	{
		Node* OldNode = pList;
		pList = pList->pNext;
		delete OldNode;
	}

}
