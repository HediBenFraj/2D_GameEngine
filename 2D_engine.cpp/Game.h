#ifndef Game_hpp
#define Game_hpp

#include "SDL.h"
#include "iostream"
#include "SDL_image.h"
using namespace std;


class Game
{
public:
	Game();
	~Game();

	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	static SDL_Renderer* renderer;
	static SDL_Event event;

	bool Running() {
		return isRunning;
	}
private :
	int cpt=0;
	bool isRunning; 
	SDL_Window *window;
	

};

#endif /* Game_hpp */