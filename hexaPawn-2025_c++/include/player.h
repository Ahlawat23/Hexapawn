#pragma once

#include <piece.h>
#include <SDL3/SDL.h>

enum class PlayerPieceState{
    idle,
    hovered,
    selected
};

// this will handle the user input
class Player: public Piece
{  
    public:
    Player() : Piece(PieceType::player) {}
    PlayerPieceState state;
    void Draw() override;

};

