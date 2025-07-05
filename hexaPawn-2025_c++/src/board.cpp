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
    //init player pieces
    for (int i = 0; i < sizeof(playerPieces)/sizeof(playerPieces[0]); i++) playerPieces[i] = new Player();
    //init enemy pieces
    for (int i = 0; i < sizeof(enemyPieces)/sizeof(enemyPieces[0]); i++)  enemyPieces[i] = new Enemy();
    //init grid and set player pieces
    for (int x = 0; x < GRID_WIDTH; x++)
    {
       for (int y = 0; y < GRID_HEIGHT; y++)
       {
            grid[x][y] = Square(x*300, y*300); 
            grid[x][GRID_HEIGHT-1].currPiece = enemyPieces[x];

       }
       grid[x][0].currPiece = playerPieces[x]; 
    }
}

/* This function runs once per frame, and it contains all the draw logic */
void Board::Draw() {

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
            if(grid[i][j].currPiece) grid[i][j].currPiece->ShowAt(xVal, yVal);

            //flip the colour
            currSquareCol = currSquareCol == SquareColour::Darker ? SquareColour::Lighter : SquareColour::Darker;

       }
    }
    
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
            SDL_SetRenderDrawColor(renderer, 2, 86, 157, SDL_ALPHA_OPAQUE); // blue
            break;
        case SquareColour::Lighter:
            SDL_SetRenderDrawColor(renderer, 3, 129, 207, SDL_ALPHA_OPAQUE); // light blue
            break;
    }
    
    //draw the square
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE); // light blue

    string label = to_string(x) + ", " + to_string(y);
    SDL_RenderDebugText(renderer, x, y, label.c_str());
    

}


