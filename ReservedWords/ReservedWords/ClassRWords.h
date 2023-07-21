#pragma once
#include <string>


struct WordElem
{
	std::string word = "";
	std::size_t count = 0;
	WordElem* next = nullptr;
};

class RLinkedList
{
public:
	RLinkedList();
	void Nappend(WordElem& arg);
	void SetC(std::string word);
	WordElem* const get_start();
	WordElem* const get_end();
	~RLinkedList();
	void Sort();
	friend std::ofstream& operator<<(std::ofstream& out, WordElem* tmp);
private:
	WordElem* start;
	WordElem* end;
};

