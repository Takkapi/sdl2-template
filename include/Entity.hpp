#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"

#undef main // Prevents conflict with SDL_main.h

class Entity {
public:
	Entity(Vector2f p_pos, SDL_Texture* p_tex);
	Vector2f& getPos() {
		return pos;
	}
	SDL_Texture* getTexture();
	SDL_Rect getCurrentFrame();
private:
	Vector2f pos;
	SDL_Rect currentFrame;
	SDL_Texture* texture;
};