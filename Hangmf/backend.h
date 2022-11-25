#pragma once

#include <fstream>
#include <string>

std::string GetWord()
{
	std::string word;
	std::ifstream input("words.in");
	input >> word;
	return word;
}

std::string LetterIsInWord(std::string current_word, char letter, std::string word)
{
	if (word.find(letter) && !current_word.find(letter))
	{
		for (int i = 0; i < word.length(); i++)
			if (word[i] == letter)
				current_word[i] = letter;
		return current_word;
	}
	else
		return NULL;
}

std::string InitGame(std::string word, int difficulty)
{
	word = GetWord();
	srand(time(NULL));

	std::string letters;
	int missing_letters;
	missing_letters = word.length() / (difficulty + 2);

	for (int i = 1; i <= missing_letters; i++)
	{
		bool found = 0;
		do
		{
			int j = rand() % word.length();
			if (!letters.find(word[j]))
			{
				letters.push_back(word[j]);
				found = 1;
			}
		} while (!found);
	}

	std::string result;
	result = word;
	for (int i = 0; i < word.length(); i++)
		if (letters.find(result[i]))
			result[i] = '_';
	return result;
}

