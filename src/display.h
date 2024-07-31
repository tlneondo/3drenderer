#ifndef DISPLAY_H
#define DISPLAY_H
#include <stdint.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "./icyHelper.h"
#include "./geom.h"

extern SDL_Window* window;
extern SDL_Renderer* renderR;
extern SDL_Texture* framebuffer_texture;
extern uint32_t* color_buffer;
extern renderSettings* windowState;

bool initialize_window(void);


void draw_Grid(SDL_Texture* texScreen, int32_t gridColor);
void draw_rect(int x, int y, int width, int height, uint32_t color);
void draw_pixel(int x, int y,uint32_t color);
void draw_imagefromFile();
void render_color_buffer();
void clear_color_buffer(uint32_t color);
void destroy_window(void);

#endif