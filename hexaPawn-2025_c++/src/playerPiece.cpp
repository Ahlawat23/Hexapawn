#include <playerPiece.h>
#include <board.h>
#include <iostream>
#include <vector>

void PlayerPiece::Draw( ){
    if(onSquare == nullptr) return;
    SDL_GetTextureSize(currTexture, &rect.w, &rect.h);
    rect.x = onSquare->xVal+ (SQUARE_WIDTH/2) - (rect.w/2);
    rect.y = onSquare->yVal+ (SQUARE_HEIGHT/2) - (rect.h/2);
    switch (state)
    {
        case PlayerPieceState::idle:
           SDL_SetTextureColorMod(currTexture, 255, 255, 255); 
            break;
        case PlayerPieceState::hovered:
           SDL_SetTextureColorMod(currTexture, 133, 209, 255); 
            break;
        case PlayerPieceState::selected:
           SDL_SetTextureColorMod(currTexture, 77, 172, 229); 
            break;
        default:
            SDL_SetTextureColorMod(currTexture, 255, 255, 255); 
            break;
    }
    SDL_RenderTexture(Board::instance().renderer, currTexture, NULL, &rect);
}

std::vector<Square*> PlayerPiece::CalValidMoves(){

    std::vector<Square*> validMoves;
    
    
    int x = onSquare->xIndex();
    int y = onSquare->yIndex();
    if(y > 0){
        //if(y-1) is idle
        //check on the forward square if it is idle or not
        Square* forward = Board::instance().grid[x][y-1];
        if(forward->currPiece == nullptr){
            forward->overlay = SquareOverlay::available;
            validMoves.push_back(forward);
        }

        //if(y-1)(x+-1) has enemy
        //check on the left square
        if(x > 0){
            Square* left = Board::instance().grid[x-1][y-1];
            if(left->currPiece != nullptr && left->currPiece->_type == PieceType::enemy){
                left->overlay = SquareOverlay::kill;
                validMoves.push_back(left);
            }
        }

        //check on the right square
        if(x < GRID_WIDTH - 1){
            Square* right = Board::instance().grid[x+1][y-1];
            if(right->currPiece != nullptr && right->currPiece->_type == PieceType::enemy){
                right->overlay = SquareOverlay::kill;
                validMoves.push_back(right);
            }
        }
    }
    
  
    return validMoves;
}