#pragma once

#include<enemy.h>

using namespace std;

class  EnemyController
{
    private:
   
    public:
    Enemy* Pieces[3] = {nullptr, nullptr, nullptr};
    static EnemyController& instance(); 
    EnemyController(/* args */);
    void DrawPieces();
     
};
