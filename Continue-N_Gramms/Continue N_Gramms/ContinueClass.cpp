#include "ContinueClass.h"

std::string GetLastWord(std::string Phrase) {
	std::string LastWord;
	size_t Idx = Phrase.length() - 1;
	while (Idx >= 0)
	{
		if (Phrase[Idx] != ' ')
		{
			LastWord = Phrase[Idx] + LastWord;
			--Idx;
			continue;
		}
		else
		{
			return LastWord;
		}

	}
}

ContinueClass::ContinueClass(std::istream& in)
{
	if (!in.good())
		exit(-1);


	while (!in.eof())
	{
		std::string key, NextWords;
		std::getline(in, key, ':');
		std::getline(in, NextWords);
		NGramms.Add(key, NextWords);
	}
}

void ContinueClass::Continue(std::string& phraseBeginning, size_t CountWords)
{
	size_t CurrentCountWords = 0;
	while (CurrentCountWords < CountWords)
	{
		if (!NGramms.IsInList(phraseBeginning))
		{
			//Нужно получить последнее слово фразы
			std::string LastWord = GetLastWord(phraseBeginning);
			if (NGramms.IsInListLast(LastWord)) {
				phraseBeginning += ' ' + LastWord;
				++CurrentCountWords;
				continue;
			}
			else
			{
				return;
			}
		}

		++CurrentCountWords;
	}
}

ContinueClass::~ContinueClass()
{
}
