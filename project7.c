#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL_image.h>

#define WIN_WIDTH 640
#define WIN_HEIGHT 480

#define SCROLL_SPEED 100


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
        WIN_WIDTH, 
        WIN_HEIGHT, 
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
    SDL_Surface* surface1 = IMG_Load("img/star.png");
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
    
    
    
    
    // Struct to save dimensions
    SDL_Rect rect1;
    SDL_QueryTexture(texture1, NULL, NULL, &rect1.w, &rect1.h);
    rect1.x = (WIN_WIDTH - rect1.w) / 2;
    
    float y_pos = WIN_HEIGHT;
    
    while (rect1.y >= -rect1.h)
    {
        //Clear window
        SDL_RenderClear(renderer1);
        rect1.y = (int) y_pos;
        
        // Draw the image
        SDL_RenderCopy(renderer1, texture1, NULL, &rect1);
        SDL_RenderPresent(renderer1);
        
        // Update position
        y_pos -= (float) SCROLL_SPEED / 60;
        
        // Wait 1/60 sec
        SDL_Delay(1000/60);    
    }
    
    
    SDL_DestroyTexture(texture1);
    SDL_DestroyRenderer(renderer1);
    SDL_DestroyWindow(window1);
    SDL_Quit();
    
    printf("Success!");
    return 0;
}
