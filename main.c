#include <stdio.h>

#include "System.h"
#include "Sand.h"

// main
int main(int argc, char* argv[])
{
    Init();

    while(isRunning)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                isRunning = 0;
            }
            else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                mouseHeld = 1;
            }
            else if(event.type == SDL_MOUSEBUTTONUP)
            {
                mouseHeld = 0;
            }
            else if(event.type == SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    isRunning = 0;
                    break;

                case SDLK_f:
                    ShuffleSandColor();
                    break;

                case SDLK_SPACE:
                    ClearSand();
                    break;
                }
            }
        }

        if(mouseHeld)
        {
            int x = 0;
            int y = 0;

            SDL_GetMouseState(&x, &y);
            FillSand(x, y);
        }

        Update();
        
        Draw(renderer);
        DrawUI();
        SDL_RenderPresent(renderer);

        SDL_Delay(1000 / FPS);
    }

    Clear();
    return 0;
}
