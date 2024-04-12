#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

bool is_running = false;
SDL_Window* window = NULL;
SDL_Renderer* renderR = NULL;


bool initialize_window(int resX, int resY){
    //configure a window
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        fprintf(stderr, "SDL init error.\n");
        return false;
    }

    //create SDL Window
    window = SDL_CreateWindow(NULL,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,resX,resY,SDL_WINDOW_BORDERLESS);

        if(!window){
            fprintf(stderr, "SDL window init error.\n");
            return false;
        }

    //Create SDL Renderer
        //first is target window
        //second parameter is display code -> -1 first defaul
        //third is no flags

    renderR == SDL_CreateRenderer(window,-1, 0);

        if(!renderR){
            fprintf(stderr, "SDL renderer init error.\n");
            return false;
        }
        
    return true;
}

int main(void){

    //sdl window
    is_running = initialize_window(800,600);
    
    return 0;
}