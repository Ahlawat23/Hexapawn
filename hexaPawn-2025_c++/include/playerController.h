#pragma once

#include<playerPiece.h>



class  PlayerController
{
    private:
    static int mouseX;
    static int mouseY;
    static int mouseButton;
   
    public:
    PlayerPiece* Pieces[3] = {nullptr, nullptr, nullptr};
    PlayerPiece* selectedPiece;

    static PlayerController& instance(); 
    PlayerController();

    void HandleInput(SDL_Event *event);
    void DrawPieces();
    bool isCursorOnPiece(PlayerPiece* Piece);
     
};


