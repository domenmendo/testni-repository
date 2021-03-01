#pragma once

#include "window.hpp"
#include <string>

class Act : public window {
public:
	Act(const window& window, int w, int h, int x, int y, const string& image_path);
	~Act();

	void draw() const;
	void pollEvents(SDL_Event& event);
	//bool CollisionDetection();

private:
	int _w, _h;
	int _x, _y;
	SDL_Texture* _texture = nullptr;
};