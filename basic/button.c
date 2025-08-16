#include "button.h" 

Button BT_create(int x,int y,int w,int h,MODE mode)
{
    return(Button)
    {
        .x = x,
        .y = y,
        .w = w,
        .h = h,
        .mode = mode,
    };
}

void BT_color(Button* button,int r,int g,int b)
{
    button->r = r; button->g = g, button->b = b;
}

void BT_draw(SDL_Renderer* renderer,Button* button,TTF_Font* font,const char* text)
{
    SDL_SetRenderDrawColor(renderer,button->r,button->g,button->b,255);    
    SDL_Rect rec = {button->x,button->y,button->w,button->h};

    SDL_RenderFillRect(renderer,&rec);
    
    drawText(renderer,font,text,button->x+2,button->y+5,0,0,0);
}
