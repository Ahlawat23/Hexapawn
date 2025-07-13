#pragma once

#include <iostream>
#include <SDL3_image/SDL_image.h>

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
    
    static void LoadTextures();
    static SDL_Texture* GetSprite(PieceType type);

    Piece(PieceType type);
    
    //for drawing
    float xVal;
    float yVal;
    void Draw();
    
};