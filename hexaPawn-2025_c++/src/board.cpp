#include <board.h>


Board::Board() {
    // Initialization code
}

Board& Board::instance() {
    static Board singleton_instance;
    return singleton_instance;
}

void Board::Init(SDL_Renderer* r){
    renderer = r;
    gridSize.x = gridSize.y = 3; 
}

/* This function runs once per frame, and it contains all the draw logic */
void Board::Draw() {

    SDL_SetRenderDrawColorFloat(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE_FLOAT);  /* new color, full alpha. */
    SDL_RenderClear(renderer);
    // DrawSquare(currSquareCol, 300, 0);
    currSquareCol = SquareColour::Darker;

    for (int i = 0; i < gridSize.x; i++)
    {
       for (int j = 0; j < gridSize.y; j++)
       {
            DrawSquare(currSquareCol, 300*i, 300*j);
            currSquareCol = currSquareCol == SquareColour::Darker ? SquareColour::Lighter : SquareColour::Darker;
       }
       
    }
    
    /* put the newly-cleared rendering on the screen. */
    SDL_RenderPresent(renderer);
}

void Board::DrawSquare(SquareColour col, int x, int y ){

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

