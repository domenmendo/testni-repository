#pragma once

#include <string>
#include <SDL.h>

using namespace std;

class window {
public:
	window(const string &title, int width, int height);
	~window();
	bool isClosed() const {
		return _closed; 
	}
	void pollEvents(SDL_Event& event);
	void clear() const;

private:
	bool init();

private:
	string _title;
	int _width = 800;
	int _height = 600;

	bool _closed = false;

	SDL_Window* _window = nullptr;

protected:
	SDL_Renderer* _renderer = nullptr;
};