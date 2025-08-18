#include "state.h" 

State* createState(const char* title,int width,int height)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    State* state = (State*)malloc(sizeof(*state));

    *state = (State)
    {
        .window = SDL_CreateWindow
        (
            title,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            SDL_WINDOW_SHOWN
        ),
        .renderer = NULL,
        .panel = NULL,
        .cTexture = NULL,
        .w = width,
        .h = height,
    };

    return state;
}

void initState(State* state)
{
    state->renderer = SDL_CreateRenderer(state->window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    state->cTexture = SDL_CreateTexture(
                                state->renderer,
                                SDL_PIXELFORMAT_RGB888,
                                SDL_TEXTUREACCESS_TARGET,
                                state->w,
                                state->h
                                );
    SDL_SetRenderTarget(state->renderer,state->cTexture);
    SDL_SetRenderDrawColor(state->renderer,255,0,0,0);
    SDL_RenderClear(state->renderer);
    SDL_SetRenderTarget(state->renderer,NULL);

    state->panel = PNL_Create(10,10,100,100,state->renderer);
    //PNL_SetSuper(state->panel,state->cTexture);
    PNL_SetColor(state->panel,255,0,255);
}

void updateState(State* state)
{
    SDL_Event e;
    bool quit = false;

    while(!quit)
    {
        while(SDL_PollEvent(&e))
        {
            switch(e.type)
            {
                case SDL_QUIT: quit = true; break;
            }
        }

        SDL_SetRenderDrawColor(state->renderer,255,255,255,255);
        SDL_RenderClear(state->renderer);

        PNL_Render(state->panel,100,10);
        SDL_RenderCopy(state->renderer,state->cTexture,NULL,NULL);

        SDL_RenderPresent(state->renderer);
    }
}

void freeState(State* state)
{
    SDL_DestroyRenderer(state->renderer);
    SDL_DestroyTexture(state->cTexture);
    SDL_DestroyWindow(state->window);
    PNL_Free(state->panel);

    free(state);

    SDL_Quit();
    TTF_Quit();
}
