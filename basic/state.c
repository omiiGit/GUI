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
        .font = TTF_OpenFont("res/dina.ttf",10),
    };
}

void initState(State* state)
{
    state->renderer = SDL_CreateRenderer(state->window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(state->font == NULL)
    {
        printf("Failed to load font! - %s\n",TTF_GetError());
    }

    state->button = BT_create(100,10,40,15,NORMAL);
    BT_color(&state->button,255,255,0);

    state->button2 = BT_create(400,10,50,15,NORMAL);
    BT_color(&state->button2,255,255,255);

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
        }

        SDL_SetRenderDrawColor(state->renderer,255,0,0,255);
        SDL_RenderClear(state->renderer);

        BT_draw(state->renderer,&state->button,state->font,"BUTTON");
        BT_draw(state->renderer,&state->button2,state->font,"BUT _ 2");

        SDL_RenderPresent(state->renderer);
    }

}
void freeState(State* state)
{
    SDL_DestroyRenderer(state->renderer);
    SDL_DestroyWindow(state->window);
}
