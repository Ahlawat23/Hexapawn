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
    Piece::LoadTextures();
    

    //init grid and set player pieces
    for (int x = 0; x < GRID_WIDTH; x++)
    {
       for (int y = 0; y < GRID_HEIGHT; y++)  grid[x][y] = Square(x*300, y*300); 

       //set up xval and yval for pieces, where they will be spawn at from the starting
       PlayerController::instance().Pieces[x]->xVal = grid[x][GRID_HEIGHT-1].x;
       PlayerController::instance().Pieces[x]->yVal = grid[x][GRID_HEIGHT-1].y;

       EnemyController::instance().Pieces[x]->xVal = grid[x][0].x;
       EnemyController::instance().Pieces[x]->yVal = grid[x][0].y;
    }
}

/* This function runs once per frame, and it contains all the draw logic */
void Board::Draw() {
    SDL_RenderClear(renderer);
    currSquareCol = SquareColour::Darker;
    //double loop to iterate through each grid cell
    for (int i = 0; i < GRID_WIDTH; i++)
    {
       for (int j = 0; j < GRID_HEIGHT; j++)
       {
            int xVal = grid[i][j].x;
            int yVal = grid[i][j].y;

            //draw the square and then draw the piece if it has any
            DrawSquare(currSquareCol, xVal, yVal);
           // if(grid[i][j].currPiece) grid[i][j].currPiece->ShowAt(xVal, yVal);

            //flip the colour
            currSquareCol = currSquareCol == SquareColour::Darker ? SquareColour::Lighter : SquareColour::Darker;

       }
    }
   
    PlayerController::instance().DrawPieces();
    EnemyController::instance().DrawPieces();
    /* put the newly-cleared rendering on the screen. */
    SDL_RenderPresent(renderer);
}

void Board::DrawSquare(SquareColour col, int x, int y )
{
    //create a rect of 300 width and height
    SDL_FRect rect;
    rect.x = x;
    rect.y = y;
    rect.w = 300;
    rect.h = 300;

    //set draw color
    switch (col) {
            break;
        case SquareColour::Darker:
            SDL_SetRenderDrawColor(renderer, 8, 89, 138, SDL_ALPHA_OPAQUE); // blue
            break;
        case SquareColour::Lighter:
            SDL_SetRenderDrawColor(renderer, 171, 220, 250, SDL_ALPHA_OPAQUE); // light blue
            break;
    }
    
    //draw the square
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE); // light blue

    string label = to_string(x) + ", " + to_string(y);
    SDL_RenderDebugText(renderer, x, y, label.c_str());
    

}


