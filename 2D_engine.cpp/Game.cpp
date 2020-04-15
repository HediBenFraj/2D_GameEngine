#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "Components.h"
#include "Vector2D.h"
//#include "Collision.h"

Map* map; 

SDL_Renderer* Game::renderer = nullptr;

SDL_Event Game::event;

Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());
Game::Game()
{
}


Game::~Game()
{
}


void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Subsystems initialized"<<endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			cout << "window created" << endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "renderer created" << endl;
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	
	map = new Map();

	player.addComponent<TransformComponent>();
	player.addComponent<SpriteComponent>("assets/player2.png");
	player.addComponent<KeyboardController>();
	//player.addComponent<ColliderComponent>("player");

	wall.addComponent<TransformComponent>(300.0, 300.0, 300, 20, 1);
	wall.addComponent<SpriteComponent>("assets/dirt.png");
	//wall.addComponent<ColliderComponent>("wall");
}

void Game::Update()
{
	manager.refresh();
	manager.update();

	if (player.getComponent<TransformComponent>().position.y > 255)
	{
		player.getComponent<SpriteComponent>().setTex("assets/player2.png");
	}
	
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	
	manager.draw();
	SDL_RenderPresent(renderer);

}

void Game::HandleEvents()
{
	
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT : 
		isRunning = false;
		break;
	default:
		break;

	}
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "game cleaned" << endl;
}