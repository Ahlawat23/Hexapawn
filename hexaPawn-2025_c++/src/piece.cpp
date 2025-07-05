#include<piece.h>
#include <board.h>


Piece::Piece(const string& imgPath, float x , float y ){
    Texture = IMG_LoadTexture(Board::instance().renderer, imgPath.c_str());
    if (!Texture) {
        SDL_Log("Couldn't load icon: %s\n", SDL_GetError());
    }
  
    rect = {x, y, RECT_SIZE, RECT_SIZE};

}

void Piece::ShowAt(float x , float y ){

    /* Center the icon and scale it up */
    // SDL_GetRenderOutputSize(Board::instance().renderer, &rect.w, RECT_SIZE);
    // SDL_SetRenderScale(Board::instance().renderer, 1.0f, 1.0f);
    SDL_GetTextureSize(Texture, &rect.w, &rect.h);
    rect.x = x;
    rect.y = y;

    /* Draw the icon */
    // SDL_SetRenderDrawColor(Board::instance().renderer, 0, 0, 0, 255);
    // SDL_RenderClear(Board::instance().renderer);
    SDL_RenderTexture(Board::instance().renderer, Texture, NULL, &rect);
    //SDL_RenderPresent(renderer);
    

}