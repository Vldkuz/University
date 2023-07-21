#pragma once
#include "LinkedList.h"
#include <string>

class ContinueClass
{
public:
	ContinueClass(std::istream& in);
	void Continue(std::string& phraseBeginning, size_t CountWords);
	~ContinueClass();
private:
	LinkedList NGramms;
};

