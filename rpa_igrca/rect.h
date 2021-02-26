#pragma once

#include "window.hpp"
#include <string>

class Rect : public window {
public:
	Rect(const window& window, int w, int h, int x, int y, const string &image_path);
	~Rect();
	
	void draw() const;
	bool pollEvents(SDL_Event& event);

private:
	int _w, _h;
	int _x, _y;
	SDL_Texture* _texture = nullptr;
};