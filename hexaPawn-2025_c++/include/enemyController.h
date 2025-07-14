#pragma once

#include<enemy.h>

class  EnemyController
{
    private:
   
    public:
    Enemy* Pieces[3] = {nullptr, nullptr, nullptr};
    static EnemyController& instance(); 
    EnemyController(/* args */);
    void DrawPieces();
    
};
