#pragma once

#include<enemyPiece.h>
#include <iostream>
#include <vector>

class  EnemyController
{
    private:
   
    public:
    EnemyPiece* Pieces[3] = {nullptr, nullptr, nullptr};
    std::vector<Square*> availableMoves;
    
    static EnemyController& instance(); 
    EnemyController(/* args */);
    void DrawPieces();
    void PlayMove();
    bool hasWon();
    
};
