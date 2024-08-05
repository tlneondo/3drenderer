#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <SDL2/SDL.h>
#include "./icyHelper.h"
#include "./geom.h"
#include "./display.h"
#include "./vec_math.h"
#include "worldObject.h"

bool is_running = false; //starting and stopping renderloop
bool is_TotalPaused = false; //pausing renderloop

void setup(void){
    color_buffer = (uint32_t*) malloc(sizeof(uint32_t) * windowState->winResX * windowState->winResY);
    framebuffer_texture = SDL_CreateTexture(
            renderR,
            SDL_PIXELFORMAT_ARGB8888,
            SDL_TEXTUREACCESS_STREAMING,
            windowState->winResX,
            windowState->winResY
        );
}

void update(void){

    

}

void testing(void){

    //testing function to run learningjobs and keep render function clean

    //draw_Grid(framebuffer_texture, 0x888888); //draw gray grid
    draw_Grid(framebuffer_texture,0x888888);
    
    
    //draw_rect(200,200,200,200,0xFFFFFF);

    //draw_pixel(250,250,0xFF0000);
    //////////////////////////////////////

    camera_t mycam = {{0,0,0}, {0.3,-2.0,0.0}, 0.78};

}


void render(void){
    SDL_SetRenderDrawColor( //paint renderer background r,g,b,a
        renderR,windowState->backGColor[0],
        windowState->backGColor[1],
        windowState->backGColor[2],
        windowState->backGColor[3]
    );

    SDL_RenderClear(renderR); // clear render
    
    //set up color buffer
    clear_color_buffer((uint32_t) 0x0);

    testing();

    render_color_buffer();

    //present render
    SDL_RenderPresent(renderR);
}

void process_input(void){
    SDL_Event event;
    SDL_PollEvent(&event); //create event and poll it

    switch(event.type){
        case SDL_QUIT: ///SDL QUIT calls X button of window
            is_running = false;
            break;

        case SDL_WINDOWEVENT_CLOSE:
            is_running = false;
            break;
        
        case SDL_WINDOWEVENT_MINIMIZED:
            //is_TotalPaused = true;
            break;

        case SDL_WINDOWEVENT_RESTORED:
            //is_TotalPaused = false;
            break;

        case SDL_KEYDOWN: //check for specific keys
            switch(event.key.keysym.sym){
                case SDLK_ESCAPE:
                    is_running = false;
                    break;
                case SDLK_LALT:
                    break;
            }
            break;

    }
}


int main(void){

    //sdl window
    is_running = initialize_window();
    
    setup();


    while(is_running){
        process_input();
        if(!is_TotalPaused){
            update();
            render();
        }

    }

    destroy_window();
    return 0;
}