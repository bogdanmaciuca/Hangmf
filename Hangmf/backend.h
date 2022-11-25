#pragma once

#include <fstream>
#include <string>

bool FindLetter(std::string text, char c)
{
	for (int i = 0; i < text.size(); i++)
		if (text[i] == c)
			return 1;
	return 0;
}

std::string ToUpper(std::string text)
{
	for (int i = 0; i < text.size(); i++)
		text[i] = std::toupper(text[i]);
	return text;
}

std::string GetWord(int difficulty)
{
	std::string word;
	int dif[3]; //number of words in each...
	std::ifstream input("words.in");
	srand(time(NULL));

	for (int i = 0; i < 3; i++)
		input >> dif[i];
	
	int line = 0;
	for (int i = 0; i < difficulty - 1; i++)
		line += dif[i];
	line += rand() % dif[difficulty-1];
	for (int i = 0; i <= line; i++)
		input >> word;
	return word;
}

bool LetterIsInWord(std::string& current_word, char letter, std::string word)
{
	if (FindLetter(word, std::tolower(letter)))
	{
		for (int i = 0; i < word.length(); i++)
			if (word[i] == std::tolower(letter))
				current_word[i] = letter;
		return 1;
	}
	else
		return 0;
}

std::string InitGame(std::string &word, int difficulty)
{
	word = GetWord(difficulty);
	srand(time(NULL));

	std::string result, letters;
	result = word;
	letters.push_back(word[0]);
	letters.push_back(word[word.length() - 1]);

	for(int i = 1; i< word.length() - 1; i++)
		if(!FindLetter(letters, result[i]))
			result[i] = '_';

	return ToUpper(result);
}

