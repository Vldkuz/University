#include "BinaryTree.h"

int BinaryTree::Find(std::string key)
{
	Node* pCurrent = pRoot;

	while (pCurrent != nullptr)
	{
		if (pCurrent->key == key)
			return pCurrent->Value;
		if (key < pCurrent->key)
			pCurrent = pCurrent->pLeft;
		else
			pCurrent = pCurrent->pRight;
	}

	return -1;
}

void BinaryTree::Add(std::string key, int value)
{
	Node* pCurrent = pRoot;
	Node* pParent = nullptr;

	while (pCurrent != nullptr)
	{
		if (pCurrent->key == key)
			pCurrent->Value = value;

		pParent = pCurrent;

		if (key < pCurrent->key)
			pCurrent = pCurrent->pLeft;
		else
			pCurrent = pCurrent->pRight;
	}

	Node* newNode = new Node();
	newNode->key = key;
	newNode->Value = value;
	newNode->pLeft = nullptr;
	newNode->pRight = nullptr;


	if (pParent == nullptr)
	{
		pRoot = newNode;
		return;
	}

	if (newNode->key < pParent->key)
	{
		pParent->pLeft = newNode;
	}
	else
	{
		pParent->pRight = newNode;
	}
}

void BinaryTree::Remove(std::string key)
{
	Node* pCurrent = pRoot;
	Node* pParent = pRoot;

	while (pCurrent != nullptr)
	{
		if (pCurrent->key == key)
			break;

		pParent = pCurrent;
		if (key < pCurrent->key)
			pCurrent = pCurrent->pLeft;
		else
			pCurrent = pCurrent->pRight;
	}

	if (pCurrent == nullptr)
	{

		return;
	}

	if (pCurrent->pRight = nullptr)
	{
		pParent->pLeft = pCurrent->pLeft;

		if (pCurrent == pRoot) {
			pRoot = pRoot->pLeft;
		}

		delete pCurrent;
		return;
	}

	//Обновить pParent
	Node* pFindNode = pCurrent->pRight;
	while (pFindNode->pLeft != nullptr)
	{
		pFindNode = pFindNode->pLeft;
	}

	pCurrent->key = pFindNode->key;
	pCurrent->Value = pFindNode->Value;

	if (pFindNode->pRight != nullptr)
	{
		/*pParent->pLeft = pFindNode;
		delete pFindNode;
		pFindNode->key = pFindNode->pRight->key;
		pFindNode->Value = pFindNode->pRight->Value;*/
	}
}
//Балансировка дерева
//Нужно перестраивать дерево
//Перенумеровать вершины с помощью топологической сортировки