#include <playerController.h>
#include <SDL3/SDL.h>
#include <piece.h>
#include <board.h>

PlayerController& PlayerController::instance() {
    static PlayerController singleton_instance;
    return singleton_instance;
}

PlayerController:: PlayerController(/* args */)
{
    //init player pieces
    for (int i = 0; i < sizeof(Pieces)/sizeof(Pieces[0]); i++) Pieces[i] = new Player();

}

 
void PlayerController::DrawPieces(){

    for (int i = 0; i < sizeof(Pieces)/sizeof(Pieces[0]); i++) {
        Pieces[i]->Draw();
    }
}
