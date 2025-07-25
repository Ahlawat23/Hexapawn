#pragma once

#include <iostream>
#include <SDL3_image/SDL_image.h>
#include <vector>
#include <config.h>


struct Square; 
class Board;   


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
    
};