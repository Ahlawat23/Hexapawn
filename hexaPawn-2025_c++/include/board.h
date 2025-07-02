#pragma once

#include <SDL3/SDL.h>

enum class SquareColour{
    Darker,
    Lighter
};


// This handles the drawing part
class Board
{
    private:
        Board();
        void DrawSquare(SDL_Renderer* renderer, SquareColour col, int x, int y );

    public:
        static Board& instance(); 

        void Draw(SDL_Renderer* renderer);
        void onceDragIsDonePlayTheEnemy();
};