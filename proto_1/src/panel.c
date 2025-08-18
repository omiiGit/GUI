#include "panel.h" 


Panel* PNL_Create(int x,int y,int w,int h,SDL_Renderer* renderer)
{
    Panel* panel = (Panel*)malloc(sizeof(*panel));

    *panel = (Panel)
    {
        .x = x,
        .y = y,
        .w = w,
        .h = h,
        .super = NULL,
        .texture = NULL,
        .renderer = renderer,
    };

    return panel;
}

void PNL_SetColor(Panel* panel,int r,int g,int b)
{
    panel->color = (SDL_Color)
    {
        .r = r,
        .g = g,
        .b = b,
        .a = 255,
    };

    panel->texture = SDL_CreateTexture(
            panel->renderer,
            SDL_PIXELFORMAT_RGB888,
            SDL_TEXTUREACCESS_TARGET,
            panel->w,
            panel->h 
            );
}

void PNL_SetSuper(Panel* panel,SDL_Texture* texture)
{
    panel->super = texture;
}

void PNL_Render(Panel* panel,int x,int y)
{
    panel->x = x; panel->y = y;

    SDL_Color color = panel->color;
    SDL_SetRenderDrawColor(panel->renderer,color.r,color.g,color.b,color.a);
    SDL_Rect rec = {panel->x,panel->y,panel->w,panel->h};

    SDL_SetRenderTarget(panel->renderer,panel->texture);
    SDL_RenderClear(panel->renderer);
    SDL_SetRenderTarget(panel->renderer,NULL);

    if(panel->super == NULL)
    {
        SDL_RenderCopy(panel->renderer,panel->texture,NULL,&rec);
    }
    else 
    {
        SDL_SetRenderTarget(panel->renderer,panel->super);
        SDL_RenderCopy(panel->renderer,panel->texture,NULL,&rec);
        SDL_SetRenderTarget(panel->renderer,NULL);
    }
}

void PNL_Free(Panel* panel)
{
    SDL_DestroyTexture(panel->texture);
    panel->renderer = NULL;
    panel->super = NULL;
}
