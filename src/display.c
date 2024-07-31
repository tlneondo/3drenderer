#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <SDL2/SDL.h>
#include "./display.h"

SDL_Window* window = NULL;
SDL_Renderer* renderR = NULL;
SDL_Texture* framebuffer_texture = NULL;
uint32_t* color_buffer = NULL;
renderSettings* windowState;

bool initialize_window(){
    windowState = malloc(sizeof(renderSettings*));
    SDL_GetCurrentDisplayMode(0,&(windowState->display_mode));

    windowState->backGColor = malloc(sizeof(int)* 4);
    windowState->backGColor[0] = 128;
    windowState->backGColor[1] = 0;
    windowState->backGColor[2] = 0;
    windowState->backGColor[3] = 0;
    windowState->winResX = 1280;
    windowState->winResY = 720;
    windowState->MaxResX = windowState->display_mode.w;
    windowState->MaxResY = windowState->display_mode.h;

    //configure a window
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        fprintf(stderr, "SDL init error.\n");
        return false;
    }

    //create SDL Window
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        windowState->winResX,
        windowState->winResY,
        SDL_WINDOW_BORDERLESS
    );

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

    //set to fullscreen borderless
    //SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN_DESKTOP);
        
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
    SDL_UpdateTexture( //update texture
                        framebuffer_texture,
                        NULL, 
                        color_buffer, 
                        (int) ( (windowState->winResX) * (sizeof(uint32_t))) //pitch / window row size
                    );
    SDL_RenderCopy(renderR,framebuffer_texture,NULL,NULL); //push texture to renderer
}

void draw_Grid(SDL_Texture* texScreen, int32_t gridColor){
    for(int y = 0; y < windowState->winResY; y++){
        for (int x = 0; x < windowState->winResX; x++){
            if ( (x) % 10 == 0 || (y % 10 ) == 0 ) {
                color_buffer[x + (windowState->winResX * y)] = gridColor;
            }          
            
        }
        
    }

}

void draw_rect(int x, int y, int width, int height, uint32_t color){

    //target x -> target x + width
    //target y -> target y + height

    //for(int i = x; i < width; i++){
    //    for(int j = y; j < height; j++){
   //         color_buffer[(x + i) + (y * j)] = color;
    //    }
//
    //}
    //following compied from pikuma course to get back in swing

    //x,y act as offsets to compute current x,y values which put pixel
     for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int current_x = x + i;
            int current_y = y + j;
            color_buffer[(windowState->winResX * current_y) + current_x] = color;
        }
    }

}

void draw_imagefromFile(){
    //SDL_Surface * bmp = SDL_LoadBMP();


}

void destroy_window(void){
    free(color_buffer);
    SDL_DestroyRenderer(renderR);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
        