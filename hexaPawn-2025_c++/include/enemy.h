#pragma once 

#include <piece.h>
// this gonna handle the ai logic
class Enemy : public Piece
{
    public:
    Enemy() : Piece(PieceType::enemy) {}

};


