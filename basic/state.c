#include "state.h" 


State createState(const char* title,int width,int height)
{
    return(State)
    {
        .window = SDL_CreateWindow(
                title,
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                width,
                height,
                SDL_WINDOW_SHOWN 
                ),
        .renderer = NULL,
        .font = NULL,
    };
}

void initState(State* state)
{
    state->renderer = SDL_CreateRenderer(state->window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(state->font == NULL)
    {
        printf("Failed to load font! - %s\n",TTF_GetError());
    }

    state->button = BT_create(200,80,BORDER);
    SDL_Color bColor = {255,0,0,0};
    SDL_Color fColor = {0,0,0,0};
    BT_init(&state->button,bColor,"res/dina.ttf",fColor);
    BT_text(&state->button,"Hello");

    state->button2 = BT_create(200,80,BORDER);
    SDL_Color b2Color = {255,255,255,0};
    SDL_Color f2Color = {0,0,0,0};
    BT_init(&state->button2,b2Color,"res/acer.ttf",f2Color);
    BT_text(&state->button2,"world");
}
void updateState(State* state)
{
    bool quit = false;
    SDL_Event e;

    while(!quit)
    {
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
            {
                quit = true;
            }
            if(e.type == SDL_MOUSEMOTION)
            {
                SDL_GetMouseState(&state->mouse.x,&state->mouse.y);
            }
            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                BT_click(&state->button,state->mouse);
                BT_click(&state->button2,state->mouse);
            }
        }

        SDL_SetRenderDrawColor(state->renderer,255,255,255,255);
        SDL_RenderClear(state->renderer);
    
        UPDATE_STATE_UI;

        DRAW_STATE_UI;

        SDL_RenderPresent(state->renderer);
        SDL_Delay(16);
        }
}

void freeState(State* state)
{
    SDL_DestroyRenderer(state->renderer);
    SDL_DestroyWindow(state->window);
    TTF_CloseFont(state->font);
}
