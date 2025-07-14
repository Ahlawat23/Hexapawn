#pragma once

#include<player.h>

using namespace std;

class  PlayerController
{
    private:
    static int mouseX;
    static int mouseY;
    static int mouseButton;
   
    public:
    Player* Pieces[3] = {nullptr, nullptr, nullptr};
    Player* selectedPiece;
    static PlayerController& instance(); 
    PlayerController(/* args */);
    void HandleInput( SDL_Event *event);
    void DrawPieces();
    bool isCursorOnPiece(Player* Piece);
     
};


