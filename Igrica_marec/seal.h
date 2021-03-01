#pragma once

#include "window.hpp"
#include <string>

class Seal : public window {
public:
	Seal(const window& window, int w, int h, int x, int y, const string& image_path);
	~Seal();

	void draw() const;
	void pollEvents(SDL_Event& event);

	int getWidth();
	int getHeight();
	int getY();
	int getX();

private:
	int _w, _h;
	int _x, _y;
	SDL_Texture* _texture = nullptr;
};
