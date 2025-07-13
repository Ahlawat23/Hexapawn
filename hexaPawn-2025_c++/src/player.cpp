#include <player.h>
#include <board.h>

void Player::Draw( ){
    SDL_GetTextureSize(currTexture, &rect.w, &rect.h);
    rect.x = xVal+ (rect.w/2);
    rect.y = yVal+ (rect.h/2);
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