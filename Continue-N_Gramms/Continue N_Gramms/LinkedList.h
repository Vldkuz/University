#pragma once
#include <iostream>
struct Node
{
	std::string phraseBeginning;
	std::string NextWords;
	Node* pNext = nullptr;
};
	

class LinkedList
{
public:
	LinkedList();
	void Add(std::string key, std::string NextWord);
	bool IsInList(std::string& key);
	bool IsInListLast(std::string& key);
	~LinkedList();
private:
	Node* pStart;
	Node* pEnd;
};

