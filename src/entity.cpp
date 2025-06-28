#include "Entity.hpp"

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex)
	:pos(p_pos), texture(p_tex) {
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 1280;
	currentFrame.h = 1280;
}

SDL_Texture* Entity::getTexture() {
	return texture;
}

SDL_Rect Entity::getCurrentFrame() {
	return currentFrame;
}