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
	while (1) {
		DrawFrame("PU_A", 3);
	}
	return 0;
}