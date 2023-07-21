//Нужно составить из файла словарь, где ключом будет начало н-граммы, а элементом будет строка NextWords
#include "ContinueClass.h"
#include <fstream>

int main()
{
	std::ifstream file("Text.txt");
	std::ifstream Text("Input.txt");
	std::ofstream Out("Output.txt");

	ContinueClass Current(file);

	std::string InputText;
	std::getline(Text, InputText);

	std::string PhraseBeginning;

	size_t Idx = 0;
	size_t CountWords = 0;
	std::string WordsCount;

	while (Idx < InputText.length())
	{
		if (isalpha(InputText[Idx]) || InputText[Idx] == ' ')
		{
			PhraseBeginning += InputText[Idx];
		}
		
		if (isdigit(InputText[Idx]))
		{
			WordsCount += InputText[Idx];
		}

		++Idx;
	}
	CountWords = std::stoi(WordsCount);
	PhraseBeginning = PhraseBeginning.substr(0, PhraseBeginning.length() - 1);

	Current.Continue(PhraseBeginning, CountWords);

	Out << PhraseBeginning << std::endl;

	return 0;
}