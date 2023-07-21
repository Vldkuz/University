#include <iostream>
#include "ClassRWords.h"
#include <fstream>

int main()
{
	std::ifstream Rfile("RWords_t.txt");
	std::ifstream Ifile("Input.txt");

	RLinkedList Rwords;

	if (!Rfile.is_open()) exit(-1);
	if (!Ifile.is_open()) exit(-1);

	while (!Rfile.eof())
	{
		WordElem* tmp = new WordElem();
		Rfile >> tmp->word;
		Rwords.Nappend(*tmp);
	}

	Rfile.close();

	while (!Ifile.eof())
	{
		std::string temp;
		Ifile >> temp;
		Rwords.SetC(temp);
	}

	Ifile.close();

	Rwords.Sort();
	std::ofstream out("Out.txt");
	WordElem* i = Rwords.get_start();

	while (i!= nullptr)
	{
		out << i->word << " "<< i->count << std::endl;
		i = i->next;
	}

	return 0;
}