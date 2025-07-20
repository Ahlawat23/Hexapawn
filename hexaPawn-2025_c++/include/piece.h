#pragma once

#include <iostream>
#include <SDL3_image/SDL_image.h>
#include <vector>


struct Square; 
class Board;   

using namespace std;

#define RECT_SIZE 150

enum class PieceType{
    player, 
    enemy
};

class  Piece
{ 
    private:
    static SDL_Texture* playerTexture;
    static SDL_Texture* enemyTexture;

    public:
    PieceType _type;
    SDL_Texture* currTexture;
    SDL_FRect rect;
    Square* onSquare;
    
    static void LoadTextures();
    static SDL_Texture* GetSprite(PieceType type);

    Piece(PieceType type);
    
    virtual void Draw();
    virtual std::vector<Square*> CalValidMoves();
    
};