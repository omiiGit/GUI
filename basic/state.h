#ifndef STATE_H 
#define STATE_H 

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include "gui.h" 


#define BUTTON_DRAW(button,x,y) BT_draw(state->renderer,&state->button,x,y)
#define BUTTON_CLICKED(button) state->button.clicked
#define BUTTON_HOVER(button) BT_hover(&state->button,state->mouse)


#define UPDATE_STATE_UI \
do{\
    if(BUTTON_CLICKED(button))\
    {\
        printf("button 1 clicked\n");\
\
        BUTTON_CLICKED(button) = false;\
    }\
    if(BUTTON_CLICKED(button2))\
    {\
        printf("button 2 clicked\n");\
\
        BUTTON_CLICKED(button2) = false;\
    }\
\
    BUTTON_HOVER(button);\
    BUTTON_HOVER(button2);\
\
}while(0)\


#define DRAW_STATE_UI \
do{\
    BUTTON_DRAW(button,10,10);\
    BUTTON_DRAW(button2,400,200);\
}while(0)\


typedef struct 
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
    vec2 mouse;

    Button button;
    Button button2;


}State;

State createState(const char* title,int width,int height);
void initState(State* state);
void updateState(State* state);
void freeState(State* state);

#endif 
