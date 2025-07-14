#include <enemyController.h>
#include<enemy.h>

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
