#pragma once

#include <iostream>
#include <SDL3_image/SDL_image.h>

using namespace std;

#define RECT_SIZE 150

class  Piece
{
    private:
     
    public:
    
    SDL_Texture* Texture = nullptr;
    SDL_FRect rect;
    Piece(const string& imgPath, float x = 0, float y = 0);

    void ShowAt(float x = 0, float y = 0);
    
};