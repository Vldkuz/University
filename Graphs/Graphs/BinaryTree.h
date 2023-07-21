#pragma once
#include <iostream>


struct Node
{
	std::string key;
	int Value;

	Node* pLeft;
	Node* pRight;
};



class BinaryTree
{
	BinaryTree();
	~BinaryTree();

	int Find(std::string key);
	void Add(std::string key, int value);
	void Remove(std::string key);

private:
	Node* pRoot;
};

