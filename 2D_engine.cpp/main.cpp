#include "Game.h"

Game *game = nullptr;
int main(int argc, char* argv[])
{

	const int FPS = 60;
	const int FRAMEDELAY = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();

	game->Init("HediEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	while (game->Running())
	{
		frameStart = SDL_GetTicks();


		game->HandleEvents();
		game->Update();
		game->Render();

		frameTime = SDL_GetTicks() - frameStart; 
		if (FRAMEDELAY > frameTime)
		{
			SDL_Delay(FRAMEDELAY - frameTime);
		}
	}
	game->Clean();
	return 0;

}