#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <SDL2/SDL.h>
#include "./icyHelper.h"

bool is_running = false;
SDL_Window* window = NULL;
SDL_Renderer* renderR = NULL;
SDL_Texture* color_buffer_texture = NULL;
uint32_t* color_buffer = NULL;



renderSettings* windowState;


bool initialize_window(int resX, int resY){

    windowState = malloc(sizeof(renderSettings*));

    windowState->backGColor = malloc(sizeof(int)* 4);
    windowState->backGColor[0] = 0;
    windowState->backGColor[1] = 0;
    windowState->backGColor[2] = 0;
    windowState->backGColor[3] = 0;
    windowState->winResX = resX;
    windowState->winResY = resY;




    //configure a window
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        fprintf(stderr, "SDL init error.\n");
        return false;
    }

    //create SDL Window
    window = SDL_CreateWindow(NULL,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,windowState->winResX,windowState->winResX,SDL_WINDOW_RESIZABLE);

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

void clear_color_buffer(uint32_t color){
    for(int y = 0; y < windowState->winResY; y++){
        for (int x = 0; x < windowState->winResX; x++){
            color_buffer[x + (windowState->winResX * y)] = color;
        }
    }
}

void render_color_buffer(){
    SDL_UpdateTexture(
                        color_buffer_texture,
                        NULL, 
                        color_buffer, 
                        (int) ( (windowState->winResX) * (sizeof(uint32_t)))
                        );

}

void destroy_window(void){
    free(color_buffer);
    SDL_DestroyRenderer(renderR);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void setup(void){

    color_buffer = malloc(sizeof(uint32_t) * windowState->winResX * windowState->winResY);
    color_buffer_texture = SDL_CreateTexture(renderR,SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_STREAMING,windowState->winResX,windowState->winResY);
    color_buffer[windowState->winResX * 10 + 20] = 0x00000000;

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
    SDL_SetRenderDrawColor(renderR,windowState->backGColor[0],windowState->backGColor[1],windowState->backGColor[2],windowState->backGColor[3]); //paint renderer background r,g,b,a
    SDL_RenderClear(renderR); // clear render

    //set up color buffer
    clear_color_buffer((uint32_t) rand());
    render_color_buffer();

    //present render
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

    destroy_window();
    return 0;
}