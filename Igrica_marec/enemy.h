#pragma once

#include "window.hpp"
#include <string>

class Enemy : public window {
public:
	Enemy(const window& window, int w, int h, int x, int y, const string& image_path);
	~Enemy();

	void draw() const;
	void pollEvents(SDL_Event& event);
	//bool CollisionDetection();

	int getWidth();
	int getHeight();
	int getY();
	int getX();

private:
	int _w, _h;
	int _x, _y;
	SDL_Texture* _texture = nullptr;
};