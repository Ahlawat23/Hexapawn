#pragma once

#include <SDL3/SDL.h>
#include <piece.h>


#define GRID_WIDTH 3
#define GRID_HEIGHT 3

#define SQUARE_HEIGHT 300
#define SQUARE_WIDTH 300

enum class SquareColour{
    Darker,
    Lighter
};

enum class SquareOverlay{
    idle,
    selected,
    available,
    kill
};

struct Square
{
    int xVal;
    int yVal;
   
    SquareColour colour;
    SquareOverlay overlay;
    Piece* currPiece = nullptr; 
    Square(SquareColour colour, int xVal = 0, int yVal = 0 ) :  colour(colour), xVal(xVal), yVal(yVal) {}
};

// A singleton class that handles the drawing part of squares, and turn logic
class Board
{
    private:
        Board();
        void DrawSquare(Square* sqr);

    public:
        SDL_Renderer* renderer = nullptr;
        Square* grid[GRID_WIDTH][GRID_HEIGHT];

        static Board& instance(); 
        void Init(SDL_Renderer* r);

        void Draw();
};