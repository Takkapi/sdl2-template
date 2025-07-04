#include "RenderWindow.hpp"
#include "Logger.hpp"

using namespace std;

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h) 
	:window(NULL), renderer(NULL) {

	Logger logger("logs.log");

	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if (window == NULL) {
		logger.log(logger.CRITICAL, "Window failed to init. Error: ");
		logger.log(logger.CRITICAL, SDL_GetError());
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath) {
	Logger logger("logs.log");
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL) {
		logger.log(logger.ERROR, "Failed to load texture. Error: ");
		logger.log(logger.ERROR, SDL_GetError());
	}

	return texture;
}

int RenderWindow::getRefreshRate() {
	int displayIndex = SDL_GetWindowDisplayIndex(window);

	SDL_DisplayMode mode;
	SDL_GetDisplayMode(displayIndex, 0, &mode);

	return mode.refresh_rate;
}

void RenderWindow::cleanUp() {
	SDL_DestroyWindow(window);
}

void RenderWindow::clear() {
	SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& p_entity) {
	SDL_Rect src;
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = p_entity.getPos().x;
	dst.y = p_entity.getPos().y;
	dst.w = p_entity.getCurrentFrame().w - 480;
	dst.h = p_entity.getCurrentFrame().h - 480;

	SDL_RenderCopy(renderer, p_entity.getTexture(), &src, &dst);
}

void RenderWindow::render(Text& p_text) {
	SDL_RenderCopy(renderer, p_text.message, NULL, &p_text.rect);
}

void RenderWindow::display() {
	SDL_RenderPresent(renderer);
}

SDL_Renderer* RenderWindow::getRenderer() {
	return renderer;
}
