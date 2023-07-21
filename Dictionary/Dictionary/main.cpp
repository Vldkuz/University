#include "Parser.h"
#include <fstream>

int main()
{
	std::ifstream IFile("Text.txt");
	std::ofstream OFile("TextO.txt");
	Parser My_Parser(2, IFile, OFile);
	My_Parser.SetList();
	My_Parser.ShowList();
	IFile.close();
	OFile.close();

	IFile.open("Text.txt");
	OFile.open("TextO.txt", std::ios::app);
	OFile <<"---------------------------------------------------------------"<< std::endl;
	Parser Your_Parser(3, IFile, OFile);
	Your_Parser.SetList();
	Your_Parser.ShowList();
	IFile.close();
	OFile.close();

	return 0;
}