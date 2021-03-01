#include "seal.h"
#include <iostream>
#include <SDL_image.h>

Seal::Seal(const window& window, int w, int h, int x, int y, const string& image_path) :
	window(window), _w(w), _h(h), _x(x), _y(y)
{
	auto surface = IMG_Load(image_path.c_str());

	if (!surface) {
		cerr << "povrsina ni bila ustvarjena(seal): " << IMG_GetError() << "\n";
		exit(EXIT_FAILURE);
	}

	_texture = SDL_CreateTextureFromSurface(_renderer, surface);

	if (!_texture) {
		cerr << "struktura ni bila ustvarjena(seal): " << IMG_GetError() << "\n";
		exit(EXIT_FAILURE);
	}

	SDL_FreeSurface(surface);
}

Seal::~Seal() {
	SDL_DestroyTexture(_texture);
}

void Seal::draw() const {
	SDL_Rect seal = { _x,_y,_w,_h };

	if (_texture) {
		SDL_RenderCopy(_renderer, _texture, nullptr, &seal);
	}
	else {
		SDL_RenderFillRect(_renderer, &seal);
	}
}

void Seal::pollEvents(SDL_Event& event) {
}

int Seal::getHeight() {
	return _h;
}
int Seal::getWidth() {
	return _w;
}
int Seal::getX() {
	return _x;
}
int Seal::getY() {
	return _y;
}
