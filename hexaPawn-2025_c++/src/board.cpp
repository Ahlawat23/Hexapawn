#include <board.h>
#include <playerController.h>
#include <enemyController.h>


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
    SquareColour currSquareCol = SquareColour::Darker;


    //init grid 
    for (int x = 0; x < GRID_WIDTH; x++)
    {
       for (int y = 0; y < GRID_HEIGHT; y++)  {
            grid[x][y] = new Square(currSquareCol, x*SQUARE_WIDTH, y*SQUARE_HEIGHT);
            currSquareCol = currSquareCol == SquareColour::Darker ? SquareColour::Lighter : SquareColour::Darker;

       }

        //set up intial position of player peices and enemy pieces
        PlayerController::instance().Pieces[x]->onSquare = grid[x][GRID_HEIGHT-1];
        grid[x][GRID_HEIGHT-1]->currPiece = PlayerController::instance().Pieces[x];

        EnemyController::instance().Pieces[x]->onSquare = grid[x][0];
        grid[x][0]->currPiece = EnemyController::instance().Pieces[x];

    }
}

/* This function runs once per frame, and it contains all the draw logic */
void Board::Draw() {
    SDL_RenderClear(renderer);
    //double loop to iterate through each grid cell
    for (int x = 0; x < GRID_WIDTH; x++)
    {
       for (int y = 0; y < GRID_HEIGHT; y++)
       {
            //draw the square and then draw the piece if it has any
            DrawSquare(grid[x][y]);
       }
    }
   
    PlayerController::instance().DrawPieces();
    EnemyController::instance().DrawPieces();
    /* put the newly-cleared rendering on the screen. */
    SDL_RenderPresent(renderer);
}

//handle everything that is related to drawing square
//inculding the selected, available and kill overlays on a square
void Board::DrawSquare(Square* sqr)
{
    //create a rect of 300 width and height
    SDL_FRect rect;
    rect.x = sqr->xVal;
    rect.y = sqr->yVal;
    rect.w = SQUARE_WIDTH;
    rect.h = SQUARE_HEIGHT;

    //set draw color
    switch (sqr->colour) {
        case SquareColour::Darker:
            SDL_SetRenderDrawColor(renderer, 8, 89, 138, SDL_ALPHA_OPAQUE); // DARKER
            break;
        case SquareColour::Lighter:
            SDL_SetRenderDrawColor(renderer, 171, 220, 250, SDL_ALPHA_OPAQUE); // LIGHTER
            break;

        default:break;
    }

    //Set overlays on the square based on state
    switch (sqr->overlay)
    {
        case SquareOverlay::idle: break;

        case SquareOverlay::selected:
            // Give a mid blue sort of colour
            SDL_SetRenderDrawColor(renderer, 11, 110, 171, SDL_ALPHA_OPAQUE); 
            break;
        case SquareOverlay::available:
            // Draw a green border for available move
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE); // green
            {
                SDL_FRect borderA = rect;
                borderA.x += 4; borderA.y += 4; borderA.w -= 8; borderA.h -= 8;
                SDL_RenderRect(renderer, &borderA);
            }
            break;
        case SquareOverlay::kill:
            // Draw a red border for kill move
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE); // red
            {
                SDL_FRect borderK = rect;
                borderK.x += 4; borderK.y += 4; borderK.w -= 8; borderK.h -= 8;
                SDL_RenderRect(renderer, &borderK);
            }
            break;
        
        default: break;
        
    }
    //draw the square
    SDL_RenderFillRect(renderer, &rect);

    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE); // light blue
    //string label = to_string(x) + ", " + to_string(y);
    //SDL_RenderDebugText(renderer, x, y, label.c_str());
    

}


