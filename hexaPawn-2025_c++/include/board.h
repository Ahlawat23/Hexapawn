#pragma once

#include <SDL3/SDL.h>
#include <piece.h>
#include<enemy.h>
#include<player.h>

using namespace std;

#define GRID_WIDTH 3
#define GRID_HEIGHT 3

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

// A singleton class that handles the drawing part of squares, pieces and taps
class Board
{
    private:
        SquareColour currSquareCol = SquareColour::Darker;
        Square grid[GRID_WIDTH][GRID_HEIGHT];
        Player* playerPieces[3] = {nullptr, nullptr, nullptr};
        Enemy* enemyPieces[3] = {nullptr, nullptr, nullptr};
        Board();
        void DrawSquare(SquareColour col, int x, int y );

    public:
        SDL_Renderer* renderer = nullptr;
        static Board& instance(); 
        void Init(SDL_Renderer* r);
        void Draw();
};