#include <playerController.h>
#include <board.h>

int PlayerController::mouseX = 0;
int PlayerController::mouseY = 0;

PlayerController& PlayerController::instance() {
    static PlayerController singleton_instance;
    return singleton_instance;
}

PlayerController:: PlayerController(/* args */)
{
    for (int i = 0; i < sizeof(Pieces)/sizeof(Pieces[0]); i++) {
        Pieces[i] = new Player();
    }

}

void PlayerController::HandleInput(SDL_Event *event){
    if (event->type == SDL_EVENT_MOUSE_MOTION) {
        mouseX = event->motion.x;
        mouseY = event->motion.y;
        SDL_Log("Mouse hover at: (%d, %d)", mouseX, mouseY);
    }

}
 
void PlayerController::DrawPieces(){

    for (int i = 0; i < sizeof(Pieces)/sizeof(Pieces[0]); i++) {
        //if the mousex and mousey falls on Pieces[i]->rect 
        //then set its state to hover
        SDL_FRect& rect = Pieces[i]->rect;
        if (mouseX >= rect.x && mouseX <= rect.x + rect.w &&
            mouseY >= rect.y && mouseY <= rect.y + rect.h) {
            Pieces[i]->state = PlayerPieceState::hovered;
        } else {
            Pieces[i]->state = PlayerPieceState::idle;
        }
        //if this piece is not selected
            //if this mouse is not getting hovered
                //set state to white
            //else
                //set state to hovered
        //else
            //draw set state to selected
        
        Pieces[i]->Draw();
    }
    string label = to_string(mouseX) + ", " + to_string(mouseY);
    //SDL_RenderDebugText(Board::instance().renderer, mouseX, mouseY, label.c_str());
}
