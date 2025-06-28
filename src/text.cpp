#include "Text.hpp"

class RenderWindow;

Text::Text(const char* p_text, Vector2f p_pos, float p_w, float p_h, SDL_Color p_color, SDL_Renderer* p_renderer) 
	:text(p_text), pos(p_pos), width(p_w), height(p_h), color(p_color) {

	TTF_Font* font = TTF_OpenFont("assets/fonts/EduNSW.ttf", 24);

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, p_text, p_color);

	message = SDL_CreateTextureFromSurface(p_renderer, surfaceMessage);

	rect.x = p_pos.x;
	rect.y = p_pos.y;
	rect.w = p_w;
	rect.h = p_h;

	SDL_RenderCopy(p_renderer, message, NULL, &rect);

	SDL_FreeSurface(surfaceMessage);
}

Text::~Text() {
	SDL_DestroyTexture(message);
}