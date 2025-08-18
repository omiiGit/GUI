#include <stdio.h> 
#include "state.h" 

int main()
{
    State* state = createState("PROTOTYPE-I",600,400);

    initState(state);
    updateState(state);
    freeState(state);

    return 0;
}
