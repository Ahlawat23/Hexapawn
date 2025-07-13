#pragma once

#include<player.h>

using namespace std;

class  PlayerController
{
    private:
    static int mouseX;
    static int mouseY;
   
    public:
    Player* Pieces[3] = {nullptr, nullptr, nullptr};
    static PlayerController& instance(); 
    PlayerController(/* args */);
    void HandleInput( SDL_Event *event);
    void DrawPieces();
     
};


