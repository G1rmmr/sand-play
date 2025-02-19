#include "Sand.h"

SDL_Color currentSandColor = {0xff, 0xff, 0, 0xff};
int colorChanges = 0;
struct Cell grid[GRID_HEIGHT][GRID_WIDTH];

// impl
void ShuffleSandColor()
{
    currentSandColor.r = rand() % (0xff + 1);
    currentSandColor.g = rand() % (0xff + 1);
    currentSandColor.b = rand() % (0xff + 1);
    currentSandColor.a = 0xff;
}

void FillSand(int x, int y)
{
    x /= GRID_SIZE;
    y /= GRID_SIZE;

    if(x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT)
    {
        grid[y][x].Type = FILL;
        grid[y][x].Color = currentSandColor;
    }
}

void Update()
{
    for(int i = GRID_HEIGHT - 2; i >= 0; --i)
    {
        for(int j = 0; j < GRID_WIDTH; ++j)
        {
            if(grid[i][j].Type == EMPTY)
            {
                continue;
            }

            if(grid[i + 1][j].Type == EMPTY)
            {
                grid[i + 1][j] = grid[i][j];
                grid[i][j].Type = EMPTY;
            }
            else if(j > 0 && grid[i + 1][j - 1].Type == EMPTY)
            {
                grid[i + 1][j - 1] = grid[i][j];
                grid[i][j].Type = EMPTY;
            }
            else if(j < GRID_WIDTH - 1 && grid[i + 1][j + 1].Type == EMPTY)
            {
                grid[i + 1][j + 1] = grid[i][j];
                grid[i][j].Type = EMPTY;
            }
        }
    }
}

void Draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
    SDL_RenderClear(renderer);

    for (int i = 0; i < GRID_HEIGHT; ++i)
    {
        for (int j = 0; j < GRID_WIDTH; ++j)
        {
            if(grid[i][j].Type == EMPTY)
            {
                continue;
            }

            SDL_SetRenderDrawColor(
                renderer,
                grid[i][j].Color.r,
                grid[i][j].Color.g,
                grid[i][j].Color.b,
                grid[i][j].Color.a);

            SDL_Rect rect = {
                j * GRID_SIZE,
                i * GRID_SIZE,
                GRID_SIZE,
                GRID_SIZE};

            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

void ClearSand()
{
    for(int i = 0; i < GRID_HEIGHT; ++i)
    {
        for(int j = 0; j < GRID_WIDTH; ++j)
        {
            grid[i][j].Type = EMPTY;
        }
    }
}