#pragma once
#include "vendor/2d_graphics/2d_graphics.h"
#include "input.h"

namespace std {
	wstring stow(const std::string& s) {
		return std::wstring(s.begin(), s.end());
	}
}

Graphics g_gui;
Graphics::TextFormat g_tf;
const float g_color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
Graphics::Sprite life_sprite;
const float life_width = 100.0f;

void InitGUI() {
	g_gui.Create("HangPerson", 800, 600);
	g_gui.CreateTextFormat(L"Consolas", 30.0f, &g_tf);
	g_gui.LoadSprite(L"res/life.png", &life_sprite);
	life_sprite.width = life_width;
	life_sprite.height = life_width;
}
void DrawLives(const char& lives) {
	for (int i = 0; i < lives; i++) {
		g_gui.DrawSprite(life_sprite, 50.0f + i * (10.0f + life_width), 50.0f);
	}
}
void DrawWord(const std::string& word) {
	g_gui.DrawText(std::stow(word).c_str(), word.size(), g_tf, 50.0f, 200.0f, 700.0f, 100.0f, (float*)g_color);
}
// Also handles messages btw
void DrawFrame(const std::string &word, const char& lives) {
	g_gui.HandleMessages();

	g_gui.BeginFrame();
	DrawWord(word);
	DrawLives(lives);
	g_gui.EndFrame();
}

