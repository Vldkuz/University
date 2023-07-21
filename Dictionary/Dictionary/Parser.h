#pragma once
#include "LinkedList.h"
class Parser
{
public:
	Parser(size_t SizeGramm, std::istream& IStream, std::ostream& OStream);
	void SetList();
	void ShowList();
	~Parser();

private:
	LinkedList* List;
	size_t N;
	std::istream& file;
	std::ostream& out;
};

