#ifndef BUTTON_H 
#define BUTTON_H 

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h> 
#include "font.h"


typedef enum 
{
    NORMAL,
    BORDER,
}MODE;



typedef struct 
{
    int x,y;
    int w,h;
    int r,g,b;

    MODE mode;

}Button; 

Button BT_create(int x,int y,int w,int h,MODE mode);
void BT_color(Button* button,int r,int g,int b);
void BT_draw(SDL_Renderer* renderer,Button* button,TTF_Font* font,const char* text);

#endif 
