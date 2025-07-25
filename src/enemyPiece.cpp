#include <enemyPiece.h>
#include <board.h>
#include <iostream>
#include <vector>

void EnemyPiece::Draw( ){
    if(onSquare == nullptr) return;
    SDL_GetTextureSize(currTexture, &rect.w, &rect.h);
    rect.x = onSquare->xVal+ (SQUARE_WIDTH/2) - (rect.w/2);
    rect.y = onSquare->yVal+ (SQUARE_HEIGHT/2) - (rect.h/2);

    SDL_RenderTexture(Board::instance().renderer, currTexture, NULL, &rect);
}


std::vector<std::pair<Square*, EnemyPiece*>> EnemyPiece::CalForwardMove(){

    std::vector<std::pair<Square*, EnemyPiece*>> validMoves;
    if(onSquare == nullptr) return validMoves;

    int x = onSquare->xIndex();
    int y = onSquare->yIndex();

    if(y < GRID_HEIGHT-1){
        //if(y+1) is idle
        //check on the forward square if it is idle or not
        Square* forward = Board::instance().grid[x][y+1];
        if(forward->currPiece == nullptr) validMoves.push_back(std::make_pair(forward, this));
    }
    
  
    return validMoves;
}


std::vector<std::pair<Square*, EnemyPiece*>> EnemyPiece::CalKillMoves(){

    std::vector<std::pair<Square*, EnemyPiece*>> validMoves;
    if(onSquare == nullptr) return validMoves;

    int x = onSquare->xIndex();
    int y = onSquare->yIndex();

    if(y < GRID_HEIGHT-1){
        //if(y+1)(x+-1) has player
        //check on the left square
        if(x > 0){
            Square* left = Board::instance().grid[x-1][y+1];
            if(left->currPiece != nullptr && left->currPiece->_type == PieceType::player) validMoves.push_back(std::make_pair(left, this));
        }

        //check on the right square
        if(x < GRID_WIDTH - 1){
            Square* right = Board::instance().grid[x+1][y+1];
            if(right->currPiece != nullptr && right->currPiece->_type == PieceType::player)  validMoves.push_back(std::make_pair(right, this));
        }
    }
    
  
    return validMoves;
}