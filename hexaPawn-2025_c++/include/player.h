#pragma once

#include <piece.h>
#include <SDL3/SDL.h>

// this will handle the user input
class Player: public Piece
{  
    public:
    Player() : Piece(PieceType::player) {}

};

