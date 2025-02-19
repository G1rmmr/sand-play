#include "System.h"

#include <stdio.h>

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
TTF_Font* font = NULL;

SDL_Event event;

int mouseHeld = 0;
int isRunning = 1;

void Init()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        isRunning = 0;
        return;
    }

    if (TTF_Init() == -1)
    {
        fprintf(stderr, "TTF_Init Error: %s\n", TTF_GetError());
        isRunning = 0;
        return;
    }

    window = SDL_CreateWindow(
        WINDOW_TITLE,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN);

    if(!window)
    {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        isRunning = 0;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        isRunning = 0;
        return;
    }

    font = TTF_OpenFont("../courier.ttf", 16);
    if(!font)
    {
        fprintf(stderr, "TTF_OpenFont Error: %s\n", TTF_GetError());
        isRunning = 0;
        return;
    }
}

void DrawUI()
{
    SDL_Color backGround = {0xff, 0xff, 0xff, 0xff};

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 150);
    SDL_Rect uiRect = {10, 10, 250, 80};
    SDL_RenderFillRect(renderer, &uiRect);

    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderDrawRect(renderer, &uiRect);

    RenderText("SPACE - Clear Sand", 20, 20, backGround);
    RenderText("F - Change Color", 20, 40, backGround);
    RenderText("ESC - Exit", 20, 60, backGround);
}

void RenderText(const char* text, int x, int y, SDL_Color color)
{
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    if(!surface)
    {
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(!texture)
    {
        SDL_FreeSurface(surface);
        return;
    }

    SDL_Rect destRect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &destRect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void Clear()
{
    if(font)
    {
        TTF_CloseFont(font);
        font = NULL;
    }

    TTF_Quit();
    
    if(renderer)
    {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }

    if(window)
    {
        SDL_DestroyWindow(window);
        window = NULL;
    }

    SDL_Quit();
}