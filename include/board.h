#pragma once

#include <SDL3/SDL.h>
#include <piece.h>
#include <SDL3_image/SDL_image.h>
#include <config.h>
#include <SDL3_ttf/SDL_ttf.h>



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

    int xIndex() const{ return xVal/300;}
    int yIndex() const{ return yVal/300;}

   
    SquareColour colour;
    SquareOverlay overlay;
    Piece* currPiece = nullptr; 
    Square(SquareColour colour, int xVal = 0, int yVal = 0 ) :  colour(colour), xVal(xVal), yVal(yVal) {}
};

// A singleton class that handles the drawing part of squares, and turn logic
class Board
{
    private:
        static SDL_Texture* availableCircle;
        static SDL_Texture* killCircle;
        
        static SDL_Texture* niceWinText;
        static SDL_Texture* hireMeText;
        static SDL_Texture* emailText;
        static SDL_Texture* failureText1;
        static SDL_Texture* failureText2;


        Board();
        void DrawSquare(Square* sqr);

    public:
        SDL_Renderer* renderer = nullptr;
        Square* grid[GRID_WIDTH][GRID_HEIGHT];
        PieceType currTurn;
        int wonPlayer = 0; //0 means games running, 1 means player won, 2 means player won

        static Board& instance(); 
        void Init(SDL_Renderer* r);
        void LoadAllFont();
        void LoadAllTexture();
        void Draw();
        void DrawAvailableCircle(int x, int y);
        void DrawKillCircle(int x, int y);

        void PassTurn();
        bool isFinished();

        void DrawGameOverScreen();
        void DrawPlayerWonScreen();
        void DrawEnemyWonScreen();

};