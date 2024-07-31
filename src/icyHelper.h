#pragma once

typedef struct renderSettings{
    int* backGColor;
    int winResX;
    int winResY;
    int MaxResX;
    int MaxResY;
    int borderLess;
    SDL_DisplayMode display_mode;
}renderSettings;                