#include "aktivist.h"
#include "utils.h"
#include <iostream>
#include <SDL_image.h>

Act::Act(const window& window, int w, int h, int x, int y, const string& image_path) :
	window(window), _w(w), _h(h), _x(x), _y(y)
{
	auto surface = IMG_Load(image_path.c_str());

	if (!surface) {
		cerr << "povrsina ni bila ustvarjena(aktivist): " << IMG_GetError() << "\n";
		exit(EXIT_FAILURE);
	}

	_texture = SDL_CreateTextureFromSurface(_renderer, surface);

	if (!_texture) {
		cerr << "struktura ni bila ustvarjena(aktivist): " << IMG_GetError() << "\n";
		exit(EXIT_FAILURE);
	}

	SDL_FreeSurface(surface);
}

Act::~Act() {
	SDL_DestroyTexture(_texture);
}

void Act::draw() const {
	SDL_Rect activist = { _x,_y,_w,_h };

	if (_texture) {
		SDL_RenderCopy(_renderer, _texture, nullptr, &activist);
	}
	else {
		cout << "no texture!!\n";
	}
}

void Act::pollEvents(SDL_Event& event) {
	int neki = rand() % (4 - 0) + 1;
	switch (neki) {
	case 1:
		if (_x > 798 || _x < 1)
			_x = -_x;
		else
			_x -= 10;
		break;
	case 2:
		if (_x > 798 || _x < 1)
			_x = -_x;
		else
			_x += 10;
		break;
	case 3:
		if (_y > 598 || _y < 1)
			_y = -_y;
		else
			_y -= 10;
		break;
	case 4:
		if (_y > 598 || _y < 1)
			_y = -_y;
		else
			_y += 10;
		break;
	}
}