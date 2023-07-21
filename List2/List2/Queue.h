#pragma once
#include <iostream>

template<class Data>
struct Node
{
	Data Value;
	Node* pNext = nullptr;
};



template <class Data>
class Queue
{
public:
	Queue() {pStart = pEnd = nullptr;}

	void push(Data Value)
	{
		Node<Data>* NewNode = new Node<Data>();
		NewNode->Value = Value;

		if (pStart == nullptr) {
			pStart = pEnd = NewNode;
			return;
		}

		pEnd->pNext = NewNode;
		pEnd = NewNode;
	};

	Data& pop()
	{
		Node<Data>* OldNode = pStart;
		pStart = pStart->pNext;
		Data Rvalue = OldNode->Value;
		delete OldNode;
		return Rvalue;
	};

	bool IsEmpty()
	{
		return pStart == nullptr;
	}

	~Queue() {
		Node<Data>* pNode = pStart;
		while (pNode != nullptr)
		{
			Node<Data>* OldNode = pNode;
			pNode = pNode->pNext;
			delete OldNode;
		}
		pStart = pEnd = nullptr;
	};

	void Clear() {
		Node<Data>* pNode = pStart;
		while (pNode != nullptr)
		{
			Node<Data>* OldNode = pNode;
			pNode = pNode->pNext;
			delete OldNode;
		}

		pStart = pEnd = nullptr;
	}

	template<class Data>
	friend std::ostream& operator<<(std::ostream& out, Queue<Data>& MyQueue)
	{
		Node<Data>* pNode = MyQueue.pStart;
		while (pNode != nullptr)
		{
			out << pNode->Value << " ";
			pNode = pNode->pNext;
		}
		return out;
	}
private:
	Node<Data>* pStart;
	Node<Data>* pEnd;
};


