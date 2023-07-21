#include "Parser.h"

Parser::Parser(size_t SizeGramm, std::istream& IStream, std::ostream& OStream): file(IStream) , out(OStream){ N = SizeGramm; List = new LinkedList();}

void Parser::ShowList() { 
	if (!out.good()) { std::cerr << "Output File is not availible" << std::endl; return; }
	List->ShowList(out); 
}

Parser::~Parser() { N = 0; delete List; }

void Parser::SetList()
{
	if (!file.good()) { std::cerr << "Input File is not availible" << std::endl; return; }

	bool IsFirst = true;
	std::streampos last;
	while (!file.eof())
	{
		std::string Str = "";

		if (!IsFirst){
			file.seekg(last);
		}

		std::getline(file,Str, '\n');
		if (Str[1] != '-') { continue; }
		size_t CountWords = 0;
		std::string key = Str.substr(2);
		std::string end = "";
		IsFirst = true;
		while (CountWords < N - 1)
		{
			if (IsFirst)
			{
				last = file.tellg();
				IsFirst = false;
			}

			std::getline(file, end, '\n');


			if (end == "") {
				return;
			}

			if (end[1] != '-') { break; }
			++CountWords;
		}

		if (end[1] != '-') { IsFirst = true; continue; }
		List->Add(key, end.substr(2));
	}

}

