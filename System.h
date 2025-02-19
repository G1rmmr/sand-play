#ifndef SYSTEM_H
#define SYSTEM_H

// headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// constants
#define WINDOW_TITLE "Test"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define FPS 60

#define GRID_SIZE 5
#define GRID_WIDTH (WINDOW_WIDTH / GRID_SIZE)
#define GRID_HEIGHT (WINDOW_HEIGHT / GRID_SIZE)

// global val
extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern TTF_Font* font;

extern SDL_Event event;

extern int mouseHeld;
extern int isRunning;

// func
void Init();
void DrawUI();
void RenderText(const char* text, int x, int y, SDL_Color color);
void Clear();

#endif