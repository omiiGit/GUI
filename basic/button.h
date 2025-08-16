#ifndef BUTTON_H 
#define BUTTON_H 

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h> 
#include <stdbool.h>
#include "font.h"


typedef enum 
{
    NORMAL,
    BORDER,
    IMAGE,
}MODE;


typedef struct 
{
    int x,y;
}vec2;

typedef struct 
{
    int x,y;
    int w,h;
    SDL_Color color;

    char* text;
    TTF_Font* font;
    SDL_Color fontColor;

    MODE mode;

    bool hover;
    bool clicked;

}Button; 

Button BT_create(int w,int h,MODE mode);
void BT_init(Button* button,SDL_Color color,const char* path,SDL_Color fontColor);
void BT_text(Button* button,char* text);

void BT_draw(SDL_Renderer* renderer,Button* button,int x,int y);
bool BT_hover(Button* button,vec2 mouse);
void BT_click(Button* button,vec2 mouse);
void BT_update(Button* button,vec2 mouse);

#endif 
