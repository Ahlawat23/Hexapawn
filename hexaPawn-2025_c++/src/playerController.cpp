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

    if(Board::instance().currTurn != PieceType::player) return;

    if (event->type == SDL_EVENT_MOUSE_MOTION) {
        mouseX = event->motion.x;
        mouseY = event->motion.y;

        int gridX = mouseX / SQUARE_WIDTH;
        int gridY = mouseY / SQUARE_HEIGHT;

        //if the current piece is not null and this piec is of type player
        auto* square = Board::instance().grid[gridX][gridY];
        if(square->currPiece != nullptr && square->currPiece->_type == PieceType::player){
            PlayerPiece* newPiece = static_cast<PlayerPiece*>(Board::instance().grid[gridX][gridY]->currPiece);
            if(mouseOnPiece != newPiece){
                if(mouseOnPiece) mouseOnPiece->state = PlayerPieceState::idle;
                mouseOnPiece = newPiece;
                mouseOnPiece->state = PlayerPieceState::hovered;
            }           
        }
        else {
            if (mouseOnPiece != nullptr) {
                mouseOnPiece->state = PlayerPieceState::idle;
                mouseOnPiece = nullptr;
            }
        }
    }

    if(mouseOnPiece == nullptr) return;

    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        mouseButton= event->button.button; // 1=left, 2=middle, 3=right
        // Handle mouse click at (x, y) with button
        
        if(mouseButton == 1){
            //set the perviously selcted piece and square to idle
            if(selectedPiece != nullptr) {
                selectedPiece->state = PlayerPieceState::idle;
                selectedPiece->onSquare->overlay = SquareOverlay::idle;
            }
            
            selectedPiece = mouseOnPiece;
            selectedPiece->state = PlayerPieceState::selected;
            selectedPiece->onSquare->overlay = SquareOverlay::selected;
         
        }

    }

}
 
void PlayerController::DrawPieces(){

    for(auto* _piece : Pieces){
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

bool PlayerController::hasWon(){
    for (size_t x = 0; x < sizeof(Pieces)/sizeof(Pieces[0]); x++) if(Pieces[x]->onSquare == Board::instance().grid[x][0]) return true;
    return false;
}
