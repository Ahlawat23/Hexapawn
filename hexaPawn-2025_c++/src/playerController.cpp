#include <playerController.h>
#include <board.h>

int PlayerController::mouseX = 0;
int PlayerController::mouseY = 0;
int PlayerController::mouseButton = 0;

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
    }
    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        mouseButton= event->button.button; // 1=left, 2=middle, 3=right
        // Handle mouse click at (x, y) with button

        if(mouseButton == 1){
            for (size_t i = 0; i < sizeof(Pieces)/sizeof(Pieces[0]); i++){
                if (PlayerController::isCursorOnPiece(Pieces[i]) && selectedPiece != Pieces[i]) {   
                    if(selectedPiece!= nullptr) selectedPiece->state = PlayerPieceState::idle;
                    selectedPiece = Pieces[i];
                    Pieces[i]->state = PlayerPieceState::selected;
                } 
            }
            
        }

    }

}
 
void PlayerController::DrawPieces(){

    for (int i = 0; i < sizeof(Pieces)/sizeof(Pieces[0]); i++) {
        //if the mousex and mousey falls on Pieces[i]->rect 
        //then set its state to hover

        //if this piece is not selected
        if(selectedPiece != Pieces[i]){
            if (!PlayerController::isCursorOnPiece(Pieces[i])) {   
                Pieces[i]->state = PlayerPieceState::idle;  
            }
            else {
                Pieces[i]->state = PlayerPieceState::hovered;
               
            }
                   
        }
        
        Pieces[i]->Draw();
    }
    //string label = to_string(mouseX) + ", " + to_string(mouseY);
    //SDL_RenderDebugText(Board::instance().renderer, mouseX, mouseY, label.c_str());
}

bool PlayerController::isCursorOnPiece(Player* Piece){
    SDL_FRect& rect = Piece->rect;
    return mouseX >= rect.x && mouseX <= rect.x + rect.w && mouseY >= rect.y && mouseY <= rect.y + rect.h;
}
