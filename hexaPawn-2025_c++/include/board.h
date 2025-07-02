#pragma once

#include <SDL3/SDL.h>

enum class SquareColour{
    Darker,
    Lighter
};

struct Vector2Int
{
    int x;
    int y;
    Vector2Int(int x =  0, int y =0) : x(x), y(y) {}
};




// This handles the drawing part
class Board
{
    private:
        SDL_Renderer* renderer = nullptr;
        Vector2Int gridSize;
        SquareColour currSquareCol = SquareColour::Darker;
        Board();
        void DrawSquare(SquareColour col, int x, int y );
        SquareColour GetSquareColour();

    public:
        static Board& instance(); 
        void Init(SDL_Renderer* r);
        void Draw();
        void onceDragIsDonePlayTheEnemy();
};