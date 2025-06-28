#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#undef main // Prevents conflict with SDL_main.h

#include "Entity.hpp"
#include "Text.hpp"

class RenderWindow {
public:
	RenderWindow(const char* p_name, int p_w, int p_h);
	SDL_Texture* loadTexture(const char* p_filePath);

	int getRefreshRate();

	void cleanUp();
	void clear();
	void render(Entity& p_entity);
	void render(Text& p_text);
	void display();

	SDL_Renderer* getRenderer();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};