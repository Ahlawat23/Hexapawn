#include <enemyController.h>
#include<enemyPiece.h>
#include <board.h>

EnemyController& EnemyController::instance() {
    static EnemyController singleton_instance;
    return singleton_instance;
}

EnemyController:: EnemyController(/* args */){
    //init player pieces
    for (int i = 0; i < sizeof(Pieces)/sizeof(Pieces[0]); i++) Pieces[i] = new EnemyPiece();
}

void EnemyController::DrawPieces(){
    for(auto* _piece : Pieces) _piece->Draw();
}


void EnemyController::PlayMove(){
    //cal all availableMoves and then pick one at random
    
}

bool EnemyController::hasWon(){
    for (size_t x = 0; x < sizeof(Pieces)/sizeof(Pieces[0]); x++) if(Pieces[x]->onSquare == Board::instance().grid[x][GRID_HEIGHT-1]) return true;
    return false;
}