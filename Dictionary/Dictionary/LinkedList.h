#pragma once
#include <iostream>
#include <string>

struct NodeEnd
{
	void SetCount(std::string pEnd);
	std::string End = "";
	size_t count = 0;
};


struct Node
{
	std::string Start = "";
	NodeEnd WrapperCount;
	Node* pNext = nullptr;
};


class LinkedList
{
public:
	LinkedList();
	void Add(std::string key,std::string end);
	void ShowList(std::ostream& out);
	~LinkedList();
private:
	Node* pStart;
	Node* pEnd;
};

//Будем хранить начало н-граммы в структуре связного списка, узел которого будет состоять из начала н-граммы и структуры счетчика, который будет содержать конец н-граммы и кол-во встреч
