#include <stdio.h>
#include <SDL2/SDL.h>

int main (int argc, char* argv)
{
    if (SDL_Init(SDL_INIT_VIDEO):=0)
    {
        printf("Error SDL Init");
        return 1;
    }    
    
    printf ("Success init!");
    SDL_Quit();
}
