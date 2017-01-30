#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL_image.h>

int main (int argc, char* argv[])
{
    //SDL initialization
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Error SDL Init: %s", SDL_GetError());
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
        printf("Window error: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Creating renderer    
    SDL_Renderer* renderer1 = SDL_CreateRenderer(window1, -1, 
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer1)
    {
        printf("Renderer error: %s", SDL_GetError());
        SDL_DestroyWindow(window1);
        SDL_Quit();
        return 1;
    }
    
    // Load image in memory
    SDL_Surface* surface1 = IMG_Load("resources/cloud015.jpg");
    if (!surface1)
    {
        printf("Surface error: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer1);
        SDL_DestroyWindow(window1);
        SDL_Quit();
        return 1;
    }
    
    // Load image to texture
    SDL_Texture* texture1 = SDL_CreateTextureFromSurface(renderer1, surface1);
    SDL_FreeSurface(surface1);
    if (!texture1)
    {
        printf("Texture error: %s", SDL_GetError());
        SDL_DestroyRenderer(renderer1);
        SDL_DestroyWindow(window1);
        SDL_Quit();
        return 1;
    }
    
    //Clear window
    SDL_RenderClear(renderer1);
    
    // Draw the image
    SDL_RenderCopy(renderer1, texture1, NULL, NULL);
    SDL_RenderPresent(renderer1);
    
       
    SDL_Delay(5000);

    SDL_DestroyTexture(texture1);
    SDL_DestroyRenderer(renderer1);
    SDL_DestroyWindow(window1);
    SDL_Quit();
    
    printf("Success!");
    return 0;
}
