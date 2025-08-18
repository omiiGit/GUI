#ifndef PANEL_H
#define PANEL_H 

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct 
{
    int x,y;
    int w,h;

    SDL_Color color;

    SDL_Texture* texture;
    SDL_Texture* super;
    SDL_Renderer* renderer;
}Panel;

Panel* PNL_Create(int x,int y,int w,int h,SDL_Renderer* renderer);
void PNL_SetColor(Panel* panel,int r,int g,int b);
void PNL_SetSuper(Panel* panel,SDL_Texture* texture);
void PNL_Render(Panel* panel,int x,int y);
void PNL_Free(Panel* panel);

#endif 
