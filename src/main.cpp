#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#undef main // Prevents conflict with SDL_main.h

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Math.hpp"
#include "Utils.hpp"
#include "Text.hpp"

#include "Logger.hpp"

using namespace std;

int main(int argc, char* args[]) {
	Logger logger("logs.log");

	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		logger.log(logger.CRITICAL, "SDL_Init has failed. SDL_Error: ");
		logger.log(logger.CRITICAL, SDL_GetError());
	}

	if(!(IMG_Init(IMG_INIT_PNG))) {
		logger.log(logger.CRITICAL, "IMG_Init has failed. SDL_Error: ");
		logger.log(logger.CRITICAL, SDL_GetError());
	}

	if(TTF_Init() != 0) {
		logger.log(logger.CRITICAL, "TTF_Init has failed. SDL_Error: ");
		logger.log(logger.CRITICAL, SDL_GetError());
	}

	logger.log(logger.INFO, "Creating window window");
	RenderWindow window("Minijam 187", 800, 800);

	logger.log(logger.DEBUG, window.getRefreshRate());

	SDL_Texture* bgTexture = window.loadTexture("assets/gfx/background.png");
	// Entity entity(Vector2f(0, 0), bgTexture);
	Text text("Text", Vector2f(100.0f, 100.0f), 50, 50, { 0, 0, 0, 0 }, window.getRenderer());

	bool gameRunning = true;

	SDL_Event event;

	const float timeStep = 0.01f;
	float accumulator = 0.0f;
	float currentTime = utils::hireTimeInSeconds();

	while (gameRunning) {
		int startTicks = SDL_GetTicks();

		float newTime = utils::hireTimeInSeconds();
		float frameTime = newTime - currentTime;

		currentTime = newTime;

		accumulator += frameTime;

		while(accumulator >= timeStep) {
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT) {
					logger.log(logger.INFO, "Received SDL_QUIT event");
					gameRunning = false;
				}
			}

			accumulator -= timeStep;
		}

		const float alpha = accumulator / timeStep;

		window.clear();
		
		// window.render(entity);
		window.render(text);
		window.display();

		int frameTicks = SDL_GetTicks() - startTicks;
		if (frameTicks < 1000 / window.getRefreshRate())
			SDL_Delay(1000/ window.getRefreshRate() - frameTicks);
	}

	logger.log(logger.INFO, "Cleaning up");
	window.cleanUp();
	
	logger.log(logger.INFO, "Quitting SDL");
	SDL_Quit();

	logger.log(logger.INFO, "Game Shutting down");
	return 0;
}