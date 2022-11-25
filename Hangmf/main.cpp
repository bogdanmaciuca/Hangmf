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
	std::string curr_word = InitGame(word, 1);
	char lives = 5;
	while (1) {
		input.Update();
		unsigned char key_pressed = 0;
		for (int i = 1; i < MAX_KEYS; i++) {
			if (input.GetKeyPressed(i)) {
				key_pressed = i;
				break;
			}
		}
		if (key_pressed && isalpha((unsigned char)key_pressed)) {
			if (islower(key_pressed)) key_pressed = std::toupper(key_pressed);
			if (!LetterIsInWord(curr_word, key_pressed, word)) {
				lives--;
			}
		}
		if (lives == 0) exit(0);
		DrawFrame(curr_word, lives);
	}
	return 0;
}