#pragma once

struct Node {
	size_t degree = 0;
	double factor = 0;
	Node* pNext = nullptr;
};


class Polynom
{
public:
	Polynom();
	Polynom(Polynom& d1);
	void add(double factor);
	Polynom* operator+(Polynom& d1);
	Polynom* operator*(Polynom& d1);
	void ShowPolynom();
	~Polynom();

private:
	size_t max_degree = 0;
	Node* pStart;
	Node* pEnd;
};
