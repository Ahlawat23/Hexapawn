#include <playerController.h>
#include <board.h>

int PlayerController::mouseX = 0;
int PlayerController::mouseY = 0;
int PlayerController::mouseButton = 0;

PlayerController& PlayerController::instance() {
    static PlayerController singleton_instance;
    return singleton_instance;
}

PlayerController:: PlayerController()
{
    for (int i = 0; i < sizeof(Pieces)/sizeof(Pieces[0]); i++)  Pieces[i] = new PlayerPiece();
}

void PlayerController::HandleInput(SDL_Event *event){

    if(!(Board::instance().currTurn != PieceType::player)) return;

    if (event->type == SDL_EVENT_MOUSE_MOTION) {
        mouseX = event->motion.x;
        mouseY = event->motion.y;
    }
    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        mouseButton= event->button.button; // 1=left, 2=middle, 3=right
        // Handle mouse click at (x, y) with button
        
        if(mouseButton == 1){
            for(auto* _piece : Pieces){
               if (PlayerController::isCursorOnPiece(_piece) && selectedPiece != _piece) { 
                      
                    if(selectedPiece != nullptr) {
                        selectedPiece->state = PlayerPieceState::idle;
                        selectedPiece->onSquare->overlay = SquareOverlay::idle;
                    }
                    selectedPiece = _piece;
                    _piece->state = PlayerPieceState::selected;
                    _piece->onSquare->overlay = SquareOverlay::selected;

                } 
            } 
        }

    }

}
 
void PlayerController::DrawPieces(){

    for(auto* _piece : Pieces){
        //if the mousex and mousey falls on Pieces[i]->rect 
        //then set its state to hover

        if(selectedPiece != _piece){
            if(!PlayerController::isCursorOnPiece(_piece)){
                _piece->state = PlayerPieceState::idle;
            } else{
                _piece->state = PlayerPieceState::hovered;
            }
        }

        _piece->Draw();
    }
    //string label = to_string(mouseX) + ", " + to_string(mouseY);
    //SDL_RenderDebugText(Board::instance().renderer, mouseX, mouseY, label.c_str());
}

bool PlayerController::isCursorOnPiece(PlayerPiece* Piece){
    SDL_FRect& rect = Piece->rect;
    return mouseX >= rect.x && mouseX <= rect.x + rect.w && mouseY >= rect.y && mouseY <= rect.y + rect.h;
}

void  PlayerController::CalculateAvailableMoveForSelected(){
    if(selectedPiece == nullptr) return;
    //logic to mark grid border as available
}
