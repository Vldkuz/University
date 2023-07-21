#pragma once
#include <iostream>
#include <string>

struct MatrixScalar
{
	double value;
	size_t i;
	size_t j;
};

struct Node
{
	MatrixScalar Scalar;
	Node* pNext = nullptr;
};

class LinkedList
{
public:
	friend class SparsedMatrix;
	Node* getStart();
	LinkedList(const LinkedList& List);
	LinkedList();
	void Add(MatrixScalar& Scalar);
	~LinkedList();
private:
	Node* pStart;
	Node* pEnd;
};

