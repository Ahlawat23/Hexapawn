#pragma once

#include<playerPiece.h>
#include <iostream>
#include <vector>

class  PlayerController
{
    private:
    static int mouseX;
    static int mouseY;
    static int mouseButton;
   
    public:
    PlayerPiece* Pieces[3] = {nullptr, nullptr, nullptr};
    Square* mouseOnSquare;
    PlayerPiece* mouseOnPiece;

    PlayerPiece* selectedPiece;
    std::vector<Square*> availableMoves;

    static PlayerController& instance(); 
    PlayerController();

    void HandleInput(SDL_Event *event);
    void DrawPieces();

    void onMouseHover();
    void onMouseDown();

    void movePiece(PlayerPiece* playerPiece, Square* newSquare);

    void resetAvailbleMoves();
    bool hasWon();
     
};


