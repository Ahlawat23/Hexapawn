#pragma once 

#include <piece.h>
#include <iostream>
#include <vector>
// this gonna handle the ai logic
class EnemyPiece : public Piece
{
    public:
    EnemyPiece() : Piece(PieceType::enemy) {}

    void Draw() override;
    std::vector<std::pair<Square*, EnemyPiece*>> CalValidMoves();

};


