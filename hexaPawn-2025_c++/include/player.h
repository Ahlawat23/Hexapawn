#pragma once

#include <piece.h>

// this will handle the user input
class Player: public Piece
{
    public:
        Player() : Piece("assets/player.png") {}
        void handleDrag();
        void validateDrag();
        void sendToBoard();
       

};

