#pragma once

#include <SDL3/SDL.h>
#include <piece.h>
#include<enemy.h>
#include<player.h>

using namespace std;

enum class SquareColour{
    Darker,
    Lighter
};




struct Square
{
    int x;
    int y;
    Piece* currPiece = nullptr; 
    Square(int x = 0, int y = 0) : x(x), y(y) {}
};


#define BOARD_WIDTH 3
#define BOARD_HEIGHT 3


// This handles the drawing part
class Board
{
    private:
        
        SquareColour currSquareCol = SquareColour::Darker;
        Square grid[BOARD_WIDTH][BOARD_HEIGHT];

        
       
        Board();
        void DrawSquare(SquareColour col, int x, int y );

    public:

        SDL_Renderer* renderer = nullptr;

        static Board& instance(); 
        void Init(SDL_Renderer* r);
        void Draw();
        void onceDragIsDonePlayTheEnemy();
};