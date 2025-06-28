#pragma once

#include <SDL2/SDL.h>

#undef main

namespace utils {
	inline float hireTimeInSeconds() {
		float t = SDL_GetTicks();
		t *= 0.001f;

		return t;
	}
}