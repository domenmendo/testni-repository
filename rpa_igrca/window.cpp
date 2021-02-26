#include "window.hpp"
#include <iostream>
#include <SDL_image.h>

window::window(const string& title, int width, int height) :
	_title(title), _width(width), _height(height)
{
	_closed = !init();
}

window::~window() {
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	IMG_Quit();
	SDL_Quit();
}

bool window::init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cerr << "sdl failed to initialize: " << IMG_GetError() << "\n";
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
		cerr << "neuspesna inicializacija SDL_image: " << IMG_GetError() << "\n";
	}

	_window = SDL_CreateWindow(
		_title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_width,
		_height,
		0
	);
	if (_window == nullptr) {
		cerr << "failed to create window.\n";
		return false;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	if (_renderer == nullptr) {
		cerr << "failed to create window.\n";
		return false;
	}

	return true;
}

void window::pollEvents(SDL_Event &event) {
	switch (event.type) {
	case SDL_QUIT:
		_closed = true;
		break;

	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			_closed = true;
			break;
		}

		case SDL_MOUSEMOTION:
			cout << event.motion.x << ", " << event.motion.y << "\n";
			break;

		/*case SDL_MOUSEBUTTONDOWN:
			cout << "kliknil si misko.\n";
			break;

		case SDL_MOUSEBUTTONUP:
			cout << "spustil si misko.\n";
			break;*/

	default:
		break;
	}
}

void window::clear() const {
	SDL_RenderPresent(_renderer);
	SDL_SetRenderDrawColor(_renderer, 30, 144, 255, 0);
	SDL_RenderClear(_renderer);
}