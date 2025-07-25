#include <board.h>
#include <playerController.h>
#include <enemyController.h>
#include <SDL3/SDL.h>
#include <config.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream> 
using std::string;
using std::to_string;

SDL_Texture* Board::availableCircle = nullptr;
SDL_Texture* Board::killCircle = nullptr;

SDL_Texture* Board::niceWinText = nullptr;
SDL_Texture* Board::hireMeText = nullptr;
SDL_Texture* Board::emailText = nullptr;
SDL_Texture* Board::failureText1 = nullptr;
SDL_Texture* Board::failureText2 = nullptr;


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
    Board::LoadAllTexture();
    Board::LoadAllFont();
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

    //set turn to player
    currTurn = PieceType::player;
}

void Board::LoadAllFont(){

    SDL_Color textColor = { 255, 255, 255, 255 };
    SDL_Surface* textSurface;
    //Load fonts
    TTF_Font* cour = TTF_OpenFont("assets/fonts/cour.ttf", 30);
    TTF_Font* courbi = TTF_OpenFont("assets/fonts/courbi.ttf", 50);
    TTF_Font* couri = TTF_OpenFont("assets/fonts/couri.ttf", 50);
    TTF_Font* oswald = TTF_OpenFont("assets/fonts/Oswald.ttf", 50);
     
    // 2. Render the text to an SDL_Surface.
    // TTF_RenderText_Blended provides high-quality text with alpha blending.
    textSurface = TTF_RenderText_Blended(cour, "pankajhlwt@gmail.com", 20, textColor);
    emailText= SDL_CreateTextureFromSurface(renderer, textSurface);

    textSurface = TTF_RenderText_Blended(courbi, "Nice win, smarty pants", 22, textColor);
    niceWinText= SDL_CreateTextureFromSurface(renderer, textSurface);

    textSurface = TTF_RenderText_Blended(couri, "Now hire me! :)", 15, textColor);
    hireMeText= SDL_CreateTextureFromSurface(renderer, textSurface);

    textSurface = TTF_RenderText_Blended(oswald, "“You must abide a great and terrible fate.", 43, textColor);
    failureText1= SDL_CreateTextureFromSurface(renderer, textSurface);

    textSurface = TTF_RenderText_Blended(oswald, "Yet, be brave of heart.”", 23, textColor);
    failureText2= SDL_CreateTextureFromSurface(renderer, textSurface);


    // 3. Create a hardware-accelerated texture from the surface.
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_DestroySurface(textSurface);

}

void Board::LoadAllTexture(){

    availableCircle = IMG_LoadTexture(Board::instance().renderer, "assets/availableCircle.png");
    if (!availableCircle) {
        SDL_Log("Couldn't load enemy texture: %s\n", SDL_GetError());
    }
      
    killCircle = IMG_LoadTexture(Board::instance().renderer, "assets/KillCircle.png");
    if (!killCircle) {
         SDL_Log("Couldn't load enemy texture: %s\n", SDL_GetError());
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
            DrawSquare(grid[x][y]);
       }
    }
   
    PlayerController::instance().DrawPieces();
    EnemyController::instance().DrawPieces();
    /* put the newly-cleared rendering on the screen. */
    DrawGameOverScreen();
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

    //Set overlays on the square
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



void Board::PassTurn(){
    
    if(!isFinished()){
        //if the turn is player, flip it and play enemy moves
        //else it was enemy turn so now give it to the player
        if(currTurn== PieceType::player){
            currTurn = PieceType::enemy;
            EnemyController::instance().PlayMove();
        } 
        else currTurn = PieceType:: player;
    }
}

bool Board::isFinished(){
    //if win show the wininning screen

    if(PlayerController::instance().hasWon()){
        wonPlayer = 1;
        return true;
    }
    else if (EnemyController::instance().hasWon()){
        wonPlayer = 2;
        return true;
    }
    else return false;

}
void Board::DrawGameOverScreen(){
    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE); // light blue
    // std::string label = *wonPlayer == PieceType::player ? "player won" : "enemy won";
    // SDL_RenderDebugText(renderer, 0, 0, label.c_str());
    if(wonPlayer == 0) return;
    if(wonPlayer == 1) DrawPlayerWonScreen();
    if(wonPlayer == 2) DrawEnemyWonScreen();
}

void Board::DrawPlayerWonScreen(){

    //draw the overlay
    SDL_FRect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = WINDOW_WIDTH;
    rect.h = WINDOW_HEIGHT;
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 191); 

    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);

    SDL_FRect textRect;

    //render email
    textRect.w = emailText->w;
    textRect.h = emailText->h;
    textRect.x = 521;
    textRect.y = 836;
    SDL_RenderTexture(renderer, emailText, NULL, &textRect);

    //render upper
    textRect.w = niceWinText->w;
    textRect.h = niceWinText->h;
    textRect.x = 120;
    textRect.y = 318;
    SDL_RenderTexture(renderer, niceWinText, NULL, &textRect);

    //render lower
    textRect.w = hireMeText->w;
    textRect.h = hireMeText->h;
    textRect.x = 225;
    textRect.y = 421;
    SDL_RenderTexture(renderer, hireMeText, NULL, &textRect);
}

void Board::DrawEnemyWonScreen(){
    //draw the overlay
    SDL_FRect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = WINDOW_WIDTH;
    rect.h = WINDOW_HEIGHT;
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 191); 

    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);

    SDL_FRect textRect;

    //render email
    textRect.w = emailText->w;
    textRect.h = emailText->h;
    textRect.x = 521;
    textRect.y = 836;
    SDL_RenderTexture(renderer, emailText, NULL, &textRect);

     //render upper
    textRect.w = failureText1->w;
    textRect.h = failureText1->h;
    textRect.x = 78;
    textRect.y = 330;
    SDL_RenderTexture(renderer, failureText1, NULL, &textRect);

    //render lower
    textRect.w = failureText2->w;
    textRect.h = failureText2->h;
    textRect.x = 243;
    textRect.y = 404;
    SDL_RenderTexture(renderer, failureText2, NULL, &textRect);
}
    
