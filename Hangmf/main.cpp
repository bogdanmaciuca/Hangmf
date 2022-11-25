#include "vendor/2d_graphics/2d_graphics.h"

#pragma comment(lib, "d2d1")
#pragma comment(lib, "dwrite")
#pragma comment(lib, "windowscodecs")
#pragma comment(lib, "Ole32")

int main() {
	// kkt
	Graphics gfx("Hang person", 800, 600);
	Graphics::TextFormat text_format;
	gfx.CreateTextFormat(L"Arial", 30, &text_format);
	float color[4] = { 0.4f, 0.5f, 0.6f, 1.0f };
	while (1) {
		gfx.HandleMessages();
		gfx.BeginFrame();
		gfx.DrawText(L"Hello mfs", 9, text_format, 100, 100, 600, 100, color);
		gfx.EndFrame();///test
	}
	return 0;
}