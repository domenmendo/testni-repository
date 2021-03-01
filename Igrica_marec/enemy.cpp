#include "enemy.h"
#include "utils.h"
#include <iostream>
#include <SDL_image.h>

Enemy::Enemy(const window& window, int w, int h, int x, int y, const string& image_path) :
	window(window), _w(w), _h(h), _x(x), _y(y)
{
	auto surface = IMG_Load(image_path.c_str());

	if (!surface) {
		cerr << "povrsina ni bila ustvarjena(enemy): " << IMG_GetError() << "\n";
		exit(EXIT_FAILURE);
	}

	_texture = SDL_CreateTextureFromSurface(_renderer, surface);

	if (!_texture) {
		cerr << "struktura ni bila ustvarjena(enemy): " << IMG_GetError() << "\n";
		exit(EXIT_FAILURE);
	}

	SDL_FreeSurface(surface);
}

Enemy::~Enemy() {
	SDL_DestroyTexture(_texture);
}

void Enemy::draw() const {
	SDL_Rect enemy = { _x,_y,_w,_h };

	if (_texture) {
		SDL_RenderCopy(_renderer, _texture, nullptr, &enemy);
	}
	else {
		cout << "no texture!!\n";
	}
}

void Enemy::pollEvents(SDL_Event& event) {
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

int Enemy::getHeight() {
	return _h;
}
int Enemy::getWidth() {
	return _w;
}
int Enemy::getX() {
	return _x;
}
int Enemy::getY() {
	return _y;
}