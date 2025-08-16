#ifndef STATE_H 
#define STATE_H 

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include "button.h" 

typedef struct 
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;

    Button button;
    Button button2;


}State;

State createState(const char* title,int width,int height);
void initState(State* state);
void updateState(State* state);
void freeState(State* state);

#endif 
