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

    if(onSquare == nullptr) return;

    // SDL_GetTextureSize(currTexture, &rect.w, &rect.h);
    // rect.x = onSquare->xVal+ (SQUARE_WIDTH/2) - (rect.w/2);
    // rect.y = onSquare->yVal+ (SQUARE_HEIGHT/2) - (rect.h/2);

    // SDL_RenderTexture(Board::instance().renderer, currTexture, NULL, &rect);
}

std::vector<Square*> Piece::CalValidMoves(){

    std::vector<Square*> validMoves;
    if(onSquare == nullptr) return validMoves;
    
    // int x = onSquare->xIndex();
    // int y = onSquare->yIndex();
    // if(y > 0){
    //     //if(y-1) is idle
    //     //check on the forward square if it is idle or not
    //     Square* forward = Board::instance().grid[x][y-1];
    //     if(forward->currPiece == nullptr){
    //         forward->overlay = SquareOverlay::available;
    //         validMoves.push_back(forward);
    //     }

    //     //if(y-1)(x+-1) has enemy
    //     //check on the left square
    //     if(x > 0){
    //         Square* left = Board::instance().grid[x-1][y-1];
    //         if(left->currPiece != nullptr && left->currPiece->_type == PieceType::enemy){
    //             left->overlay = SquareOverlay::kill;
    //             validMoves.push_back(left);
    //         }
    //     }

    //     //check on the right square
    //     if(x < GRID_WIDTH - 1){
    //         Square* right = Board::instance().grid[x+1][y-1];
    //         if(right->currPiece != nullptr && right->currPiece->_type == PieceType::enemy){
    //             right->overlay = SquareOverlay::kill;
    //             validMoves.push_back(right);
    //         }
    //     }
    // }
    
  
    return validMoves;
}