#include <stdio.h> 
#include "state.h" 

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    State window = createState("GUI",800,600);

    initState(&window);
    updateState(&window);
    freeState(&window);

    TTF_Quit();
    SDL_Quit();

    return 0;
}
