#pragma once

#include <piece.h>
#include <iostream>
#include <vector>


enum class PlayerPieceState{
    idle,
    hovered,
    selected
};

// this will handle the user input
class PlayerPiece: public Piece
{  
    public:
    PlayerPieceState state;
    PlayerPiece() : Piece(PieceType::player) {}

    void Draw() override;
    std::vector<Square*> CalValidMoves();
    std::vector<Square*> peekValidMoves();

};

