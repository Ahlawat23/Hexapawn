#include<piece.h>
#include <board.h>


Piece::Piece(const string& imgPath, float x , float y ){
    Texture = IMG_LoadTexture(Board::instance().renderer, imgPath.c_str());
  
    rect = {x, y, RECT_SIZE, RECT_SIZE};

}

void Piece::ShowAt(int x , int y ){
    rect.x = x;
    rect.y = y;
    SDL_RenderTexture(Board::instance().renderer, Texture, NULL, &rect);

}