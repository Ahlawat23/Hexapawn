#pragma once

#include<player.h>

using namespace std;

class  PlayerController
{
    private:
   
    public:
    Player* Pieces[3] = {nullptr, nullptr, nullptr};
    static PlayerController& instance(); 
    PlayerController(/* args */);
    void DrawPieces();
     
};


