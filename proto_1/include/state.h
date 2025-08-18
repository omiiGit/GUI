#ifndef STATE_H
#define STATE_H 

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include "panel.h"

typedef struct 
{
    int w,h;
    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* cTexture;
    
    Panel* panel;

}State;

State* createState(const char* title,int width,int height);
void initState(State* state);
void updateState(State* state);
void freeState(State* state);

#endif 
