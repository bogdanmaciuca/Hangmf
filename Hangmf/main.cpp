#include <string>
#include <vector>

#include "frontend.h"
#include "backend.h"

#pragma comment(lib, "d2d1")
#pragma comment(lib, "dwrite")
#pragma comment(lib, "windowscodecs")
#pragma comment(lib, "Ole32")

int main() {
	InitGUI();
	Input input;

	std::string word = "";
	std::string curr_word = InitGame("CUVANT", 1);
	char lives = 3;

	while (1) {
		input.Update();
		char key_pressed = 0;
		for (int i = 0; i < MAX_KEYS; i++) {
			if (input.GetKeyPressed(i)) key_pressed = i;
		}
		if (key_pressed && isalpha(key_pressed)) {
			if (islower(key_pressed)) key_pressed -= 32;
			if (LetterIsInWord(curr_word, key_pressed, word) == "") {
				lives--;
			}
		}
		DrawFrame(word, lives);
	}
	return 0;
}