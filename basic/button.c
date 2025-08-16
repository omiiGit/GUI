#include "button.h" 

Button BT_create(int w,int h,MODE mode)
{
    return(Button)
    {
        .w = w,
        .h = h,
        .mode = mode,
        .font = NULL,
        .hover = false,
        .clicked = false,
    };
}

void BT_init(Button* button,SDL_Color color,const char* path,SDL_Color fontColor)
{
    button->color = color;
    button->font = TTF_OpenFont(path,20);
    button->fontColor = fontColor;

    if(button->font == NULL)
    {
        printf("Failed to load font - %s",TTF_GetError());
    }
}

void BT_text(Button* button,char* text)
{
    button->text = text;
}

void BT_draw(SDL_Renderer* renderer,Button* button,int x,int y)
{

    button->x = x; button->y = y;
    SDL_Color color;

    if(button->hover)
    {
        color = (SDL_Color){.r = 255,.g = 255,.b = 0,.a = 255};
        button->hover = false;
    }
    else
    {
        color = button->color;
    }


    SDL_Surface* fontSurface = TTF_RenderText_Solid(button->font,button->text,button->fontColor);
    SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(renderer,fontSurface);

    int tw = fontSurface->w;
    int th = fontSurface->h;

    SDL_Rect rec = {button->x,button->y,button->w,button->h};

    int r = button->color.r; int g = color.g; int b = color.b; int a = color.a;
    SDL_SetRenderDrawColor(renderer,r,g,b,a);
    SDL_RenderFillRect(renderer,&rec);

    int sx = (button->w/2-tw/2) + button->x;
    int sy = (button->h/2-th/2) + button->y;

    SDL_Rect recFont = {sx,sy,tw,th};
    SDL_RenderCopy(renderer,fontTexture,NULL,&recFont);

    SDL_FreeSurface(fontSurface);
    SDL_DestroyTexture(fontTexture);
    
    if(button->mode == BORDER)
    {
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_Rect border = {button->x,button->y,button->w,button->h};

        SDL_RenderDrawRect(renderer,&border);
    }

}

bool BT_hover(Button* button,vec2 mouse)
{
    if(mouse.x >= button->x && mouse.x <= button->x + button->w &&
       mouse.y >= button->y && mouse.y <= button->y + button->h)
    {
        button->hover = true;
        return true;
    }
    else
    {
        button->hover = false;
        return false;
    }

}

void BT_click(Button* button,vec2 mouse)
{
    if(mouse.x >= button->x && mouse.x <= button->x + button->w &&
       mouse.y >= button->y && mouse.y <= button->y + button->h)
    {
        button->clicked = true;
    }
    else 
    {
        button->clicked = false;
    }
}

