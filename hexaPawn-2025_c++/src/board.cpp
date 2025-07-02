#include <board.h>


Board::Board() {
    // Initialization code
}

Board& Board::instance() {
    static Board singleton_instance;
    return singleton_instance;
}

/* This function runs once per frame, and it contains all the draw logic */
void Board::Draw(SDL_Renderer* renderer) {

    SDL_SetRenderDrawColorFloat(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE_FLOAT);  /* new color, full alpha. */
    SDL_RenderClear(renderer);

    DrawSquare(renderer, SquareColour::Darker, 0, 0);
    

    /* put the newly-cleared rendering on the screen. */
    SDL_RenderPresent(renderer);
}

void Board::DrawSquare(SDL_Renderer* renderer, SquareColour col, int x, int y ){

    SDL_FRect rect;
    rect.x = x;
    rect.y = y;
    rect.w = 300;
    rect.h = 300;

    switch (col) {
            break;
        case SquareColour::Darker:
            SDL_SetRenderDrawColor(renderer, 2, 86, 157, SDL_ALPHA_OPAQUE); // blue
            break;
        case SquareColour::Lighter:
            SDL_SetRenderDrawColor(renderer, 3, 129, 207, SDL_ALPHA_OPAQUE); // light blue
            break;
    }
    SDL_RenderFillRect(renderer, &rect);

}

void Board::onceDragIsDonePlayTheEnemy() {
    // Enemy move code
}

