#pragma once
#include <SDL2/SDL_ttf.h>
#include <string>

#include "Math.hpp"

using namespace std;

class Text {
public:
	Text(const char* p_text, Vector2f p_pos, float p_w, float p_h, SDL_Color p_color, SDL_Renderer* p_renderer);
	~Text();

	const char* text;
	Vector2f pos;
	float width, height;
	SDL_Color color;
	SDL_Texture* message;
	SDL_Rect rect;
private:
};