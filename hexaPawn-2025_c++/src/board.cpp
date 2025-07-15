#include <board.h>
#include <playerController.h>
#include <enemyController.h>
#include <SDL3/SDL.h>

SDL_Texture* Board::availableCircle = nullptr;
SDL_Texture* Board::killCircle = nullptr;

Board::Board() {
  // Initialization code
}

Board& Board::instance() {
    static Board singleton_instance;
    return singleton_instance;
}

void Board::Init(SDL_Renderer* r){
    renderer = r;
    //Load Textures 
    availableCircle = IMG_LoadTexture(Board::instance().renderer, "assets/availableCircle.png");
    if (!availableCircle) {
        SDL_Log("Couldn't load enemy texture: %s\n", SDL_GetError());
    }
      
    killCircle = IMG_LoadTexture(Board::instance().renderer, "assets/KillCircle.png");
    if (!killCircle) {
         SDL_Log("Couldn't load enemy texture: %s\n", SDL_GetError());
    } 

    Piece::LoadTextures();


    //init grid 
    SquareColour currSquareCol = SquareColour::Darker;

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

    SDL_RenderFillRect(renderer, &rect);

    //Set overlays on the square based on state
    switch (sqr->overlay)
    {
        case SquareOverlay::idle: 
        break;
        case SquareOverlay::selected:
            SDL_SetRenderDrawColor(renderer, 11, 110, 171, SDL_ALPHA_OPAQUE);
            SDL_RenderFillRect(renderer, &rect);
        break;
        case SquareOverlay::available:  DrawAvailableCircle(rect.x, rect.y);
        break;
        case SquareOverlay::kill: DrawKillCircle(rect.x, rect.y);
        break;
        default: break;
        
    }
    //draw the square

    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE); // light blue
    //string label = to_string(x) + ", " + to_string(y);
    //SDL_RenderDebugText(renderer, x, y, label.c_str());
    

}


void Board::DrawAvailableCircle(int x, int y)
{
    SDL_FRect rect;
    SDL_GetTextureSize(availableCircle, &rect.w, &rect.h);
    rect.x = x+ (SQUARE_WIDTH/2) - (rect.w/2);
    rect.y = y+ (SQUARE_HEIGHT/2) - (rect.h/2);

    SDL_RenderTexture(Board::instance().renderer, availableCircle, NULL, &rect);
}

void Board::DrawKillCircle(int x, int y){

    SDL_FRect rect;
    SDL_GetTextureSize(killCircle, &rect.w, &rect.h);
    rect.x = x+ (SQUARE_WIDTH/2) - (rect.w/2);
    rect.y = y+ (SQUARE_HEIGHT/2) - (rect.h/2);

    SDL_RenderTexture(Board::instance().renderer, killCircle, NULL, &rect);
}