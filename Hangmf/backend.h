#pragma once

#include <fstream>
#include <string>

std::string GetWord(int difficulty)
{
	std::string word;
	int dif[3]; //number of words in each...
	std::ifstream input("words.in");
	/*
	for (int i = 0; i < 3; i++)
		input >> dif[i];
	
	int line = 0;
	for (int i = 0; i < difficulty - 1; i++)
		line += dif[i];
	line += rand() % dif[difficulty];
	for (int i = 1; i <= line; i++)
	
	*/
		input >> word;
	return word;
}

bool LetterIsInWord(std::string &current_word, char letter, std::string word)
{
	if (word.find(letter) && !current_word.find(letter))
	{
		for (int i = 0; i < word.length(); i++)
			if (word[i] == letter)
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

	std::string letters;
	
	letters.push_back(word[0]);
	letters.push_back(word[word.length()-1]);

	std::string result;
	result = word;
	for(int i = 1; i< word.length() - 1; i++)
		result[i] = '_';

	/*
	for (int i = 0; i < word.length(); i++)
		if (letters.find(result[i]))
			result[i] = '_';
	*/
	return result;
}

