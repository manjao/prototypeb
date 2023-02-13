#ifdef PROTOTYPEB_GAMESTATE_H
#else

#include <SDL.h>
#include <iostream>
#include <vector>
#include "ValidUnits.h"

const unsigned short _DEFAULT_FPS = 60;
const int _HEIGHT = 640, _WEIGHT = 480;

class GameWindow
{
public:
	GameWindow(int height = _HEIGHT, int weigth = _WEIGHT, unsigned short fps = _DEFAULT_FPS);
	~GameWindow();

	void run();
	void render();
	void stop(); 
	inline void status() const;

private:
	int height, weigth;
	unsigned short target_fps;

	bool should_run;

	ValidUnits* units;

	SDL_Renderer* renderer;
	SDL_Window* window;

};

#endif