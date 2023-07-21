#include "ClassRWords.h"
#include <fstream>

void SwapWE(WordElem& d1, WordElem& d2)
{
	WordElem tmp;
	tmp.count = d1.count;
	tmp.word = d1.word;
	tmp.next = d1.next;

	d1.count = d2.count;
	d1.word = d2.word;
	d1.next = d2.next;

	d2.count = tmp.count;
	d2.word = tmp.word;
	d2.next = tmp.next;
}


RLinkedList::RLinkedList()
{
	start = nullptr;
	end = nullptr;
}

void RLinkedList::Nappend(WordElem& arg)
{
	if (start == nullptr) {
		start = &arg; end = &arg; return;
	}

	WordElem* tmp = start;
	while (tmp != nullptr)
	{
		if (tmp->word == arg.word)
			return;
		tmp = tmp->next;
	}

	end->next = &arg;
	end = &arg;
}

void RLinkedList::SetC(std::string word)
{
	if (start == nullptr)
		return;

	WordElem* tmp = start;
	while (tmp!= nullptr)
	{
		if (tmp->word == word)
			++tmp->count;

		tmp = tmp->next;
	}
}



WordElem* const RLinkedList::get_start() { return start;}
WordElem* const RLinkedList::get_end() {return end;}

RLinkedList::~RLinkedList()
{

}

void RLinkedList::Sort()
{
	WordElem* i = start;
	while (i->next != nullptr) {

		WordElem* j = i->next;
		while (j != nullptr)
		{
			if (i->count < j->count)
				SwapWE(*i, *j);

			j = j->next;
		}

		i = i->next;
	}
}

std::ofstream& operator<<(std::ofstream& out, WordElem* tmp)
{
	out << tmp->word <<" "<< tmp->count << std::endl;
	return out;
}
