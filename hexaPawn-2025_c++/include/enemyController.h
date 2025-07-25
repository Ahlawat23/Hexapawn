#pragma once

#include<enemyPiece.h>
#include <iostream>
#include <vector>

class  EnemyController
{
    private:
   
    public:
    EnemyPiece* Pieces[3] = {nullptr, nullptr, nullptr};
    std::vector<std::pair<Square*, EnemyPiece*>> availableMoves;
    bool isHard;
    
    static EnemyController& instance(); 
    EnemyController(/* args */);

    void DrawPieces();

    void PlayMove();
    void PlayEasy();
    void PlayHard();
    void movePiece(EnemyPiece* playerPiece, Square* newSquare);

    bool hasWon();
    
};
