#pragma once

#include <piece.h>

enum class PlayerPieceState{
    idle,
    hovered,
    selected
};

// this will handle the user input
class PlayerPiece: public Piece
{  
    public:
    PlayerPiece() : Piece(PieceType::player) {}
    PlayerPieceState state;
    void Draw() override;

};

