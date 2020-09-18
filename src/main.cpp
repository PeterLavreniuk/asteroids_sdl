#include <iostream>
#include <SDL2/SDL.h>
#include "Ship.h"
#include "Globals.h"
#include "EntitiesCollection.h"
#include "ShipInputHandler.h"

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;
EntitiesCollection* entitiesCollection = nullptr;
Ship* ship = nullptr;
ShipInputHandler* shipInputHandler = nullptr;

bool init(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << SDL_GetError();
        return false;
    }

    gWindow = SDL_CreateWindow("ASTEROIDS",
                               SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               SCREEN_WIDTH,
                               SCREEN_HEIGHT,
                               SDL_WINDOW_SHOWN);

    if(gWindow == nullptr){
        std::cout << SDL_GetError() << std::endl;
        return false;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if(gRenderer == nullptr){
        std::cout << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

void clear(){
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main() {
    ship = new Ship(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    entitiesCollection = new EntitiesCollection(ship);
    shipInputHandler = new ShipInputHandler(ship, entitiesCollection);

    if(!init()){
        std::cout << "init failed" << std::endl;
        clear();
        return 0;
    }

    auto quit = false;
    SDL_Event e;

    int sleep = 0;
    Uint32 next_game_tick = SDL_GetTicks();

    const Uint8* state = SDL_GetKeyboardState(NULL);

    while(!quit){
        if(state[SDL_SCANCODE_ESCAPE]){
            quit = true;
        }
        shipInputHandler->handle(state);

        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT){
                quit = true;
            }

            shipInputHandler->handle(e.key.keysym.sym);
        }

        SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(gRenderer);

        entitiesCollection->checkCollisions();
        entitiesCollection->generateEntities();
        entitiesCollection->updateEntities();
        entitiesCollection->renderEntities(gRenderer);

        SDL_RenderPresent(gRenderer);

        next_game_tick += 1000 / 60;
        sleep = next_game_tick - SDL_GetTicks();

        if( sleep >= 0 ) {
            SDL_Delay(sleep);
        }
    }

    clear();

    return 0;
}