#include <enemyController.h>
#include<enemy.h>
#include <board.h>

EnemyController& EnemyController::instance() {
    static EnemyController singleton_instance;
    return singleton_instance;
}

EnemyController:: EnemyController(/* args */)
{
    //init player pieces
    for (int i = 0; i < sizeof(Pieces)/sizeof(Pieces[0]); i++) Pieces[i] = new Enemy();

}

 
void EnemyController::DrawPieces(){

    for (int i = 0; i < sizeof(Pieces)/sizeof(Pieces[0]); i++) {
        Pieces[i]->Draw();
    }
}

void EnemyController::PlayMove(){
    
}

bool EnemyController::hasWon(){
    for (size_t x = 0; x < sizeof(Pieces)/sizeof(Pieces[0]); x++) if(Pieces[x]->onSquare == Board::instance().grid[x][GRID_HEIGHT-1]) return true;
    return false;
}