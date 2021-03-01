#include "rect.h"
#include "enemy.h"
#include <iostream>
#include <SDL_image.h>

Rect::Rect(const window& window, int w, int h, int x, int y, const string &image_path) :
	window(window), _w(w), _h(h), _x(x), _y(y)
{
	auto surface = IMG_Load(image_path.c_str());

	if (!surface) {
		cerr << "povrsina ni bila ustvarjena(igralec): "<< IMG_GetError() << "\n";
		exit(EXIT_FAILURE);
	}

	_texture = SDL_CreateTextureFromSurface(_renderer, surface);

	if (!_texture) {
		cerr << "struktura ni bila ustvarjena(igralec): " << IMG_GetError() << "\n";
		exit(EXIT_FAILURE);
	}

	SDL_FreeSurface(surface);
}

Rect::~Rect() {
	SDL_DestroyTexture(_texture);
}

void Rect::draw() const {
	SDL_Rect rect = { _x,_y,_w,_h };
	
	if (_texture) {
		SDL_RenderCopy(_renderer, _texture, nullptr, &rect);
	}
	else {
		cout << "no texture!!\n";
	}
}

bool Rect::pollEvents(SDL_Event &event) {
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			_x -= 10;
			break;
		case SDLK_RIGHT:
			_x += 10;
			break;
		case SDLK_DOWN:
			_y += 10;
			break;
		case SDLK_UP:
			_y -= 10;
			break;
		}
		return true;
	}
	else
		return false;
}

bool Rect::CollisionDetection(Enemy& a) {
	if (_x + _w<a.getX() || _x>a.getX() + a.getWidth() || _y + _h<a.getY() || _y>a.getY() + a.getHeight()) {
		delete &a;
		return false;
	}
	else {
		return true;
	}
}

bool Rect::CollisionDetection(Seal& b) {
	if (_x + _w<b.getX() || _x>b.getX() + b.getWidth() || _y + _h<b.getY() || _y>b.getY() + b.getHeight()) {
		return false;
	}
	else {
		return true;
	}
}