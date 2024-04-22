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

    renderR = SDL_CreateRenderer(window,-1, 0);

        if(!renderR){
            fprintf(stderr, "SDL renderer init error.\n");
            return false;
        }
        
    return true;
}

void setup(void){

}

void process_input(void){
    SDL_Event event;
    SDL_PollEvent(&event); //create event and poll it

    switch(event.type){
        case SDL_QUIT: ///SDL QUIT calls X button of window
            is_running = false;
            break;
        case SDL_KEYDOWN: //check for specific keys
            switch(event.key.keysym.sym){
                case SDLK_ESCAPE:
                    is_running = false;
                    break;
            }
            break;

    }
}

void update(void){

}

void render(void){
    SDL_SetRenderDrawColor(renderR,128,5,128,255 ); //paint renderer,r,g,b,a
    SDL_RenderClear(renderR); // clear render

    SDL_RenderPresent(renderR);

}

int main(void){

    //sdl window
    is_running = initialize_window(800,600);
    
    setup();

    while(is_running){
        process_input();
        update();
        render();
    }


    return 0;
}