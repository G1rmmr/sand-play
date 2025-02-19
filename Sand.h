#ifndef SAND_H
#define SAND_H

// headers
#include "System.h"

#include <stdlib.h>
#include <time.h>

// Cell
enum CellType
{
    EMPTY,
    FILL
};

struct Cell
{
    enum CellType Type;
    SDL_Color Color;
};

// global val
extern SDL_Color currentSandColor;
extern int colorChanges;
extern struct Cell grid[GRID_HEIGHT][GRID_WIDTH];

// func
void ShuffleSandColor();
void FillSand(int x, int y);
void Update();
void Draw(SDL_Renderer* renderer);
void ClearSand();

#endif