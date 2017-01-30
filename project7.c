#include <stdio.h>
#include <SDL2/SDL.h>

int main (int argc, char* argv[])
{
    //SDL initialization
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Error SDL Init");
        return 1;
    }    
    
    //Create window
    SDL_Window* window1 = SDL_CreateWindow 
    (
        "Hello!",
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED,
        640, 
        480, 
        0
    );
    
    if(!window1)
    {
        printf("Window error!");
        SDL_Quit();
        return 1;
    }
    
    SDL_Delay(3000);
    SDL_DestroyWindow(window1);
     
    printf ("Success!\n");
    SDL_Quit();
}
