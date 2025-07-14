#include<piece.h>
#include <board.h>

SDL_Texture* Piece::playerTexture = nullptr;
SDL_Texture* Piece::enemyTexture = nullptr;

Piece::Piece(PieceType type){
    _type = type;
    currTexture = Piece::GetSprite(_type);
    rect = {0, 0, RECT_SIZE, RECT_SIZE};

}

void Piece::LoadTextures(){ 
   
        
    playerTexture = IMG_LoadTexture(Board::instance().renderer, "assets/player.png");
    if (!playerTexture) {
        SDL_Log("Couldn't load enemy texture: %s\n", SDL_GetError());
    }
      
    enemyTexture = IMG_LoadTexture(Board::instance().renderer, "assets/enemy.png");
    if (!enemyTexture) {
         SDL_Log("Couldn't load enemy texture: %s\n", SDL_GetError());
    }
           

}

SDL_Texture* Piece::GetSprite(PieceType type){

    switch (type)
    {
        case PieceType::player:
            return playerTexture;

        case PieceType::enemy:
           return enemyTexture;
           
        default:
            return nullptr;
    }

}
 
void Piece::Draw( ){
    SDL_GetTextureSize(currTexture, &rect.w, &rect.h);
    rect.x = onSquare->xVal+ (rect.w/2);
    rect.y = onSquare->yVal+ (rect.h/2);

    SDL_RenderTexture(Board::instance().renderer, currTexture, NULL, &rect);
}