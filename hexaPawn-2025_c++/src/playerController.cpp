#include <playerController.h>
#include <board.h>
#include <iostream>
#include <vector>

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
        onMouseHover();
    }

    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        mouseButton= event->button.button; // 1=left, 2=middle, 3=right
        if(mouseButton == 1) onMouseDown(); 
    }

}

void PlayerController::onMouseHover(){
    int gridX = mouseX / SQUARE_WIDTH;
    int gridY = mouseY / SQUARE_HEIGHT;

    //find the square it is on
    mouseOnSquare = Board::instance().grid[gridX][gridY];

    if(mouseOnSquare->currPiece == nullptr || mouseOnSquare->currPiece->_type != PieceType::player ){
        if(mouseOnPiece) mouseOnPiece->state = PlayerPieceState::idle;
        mouseOnPiece = nullptr;
        return;
    }
    //store it in a temp piece
    PlayerPiece* tempPiece = static_cast<PlayerPiece*>(Board::instance().grid[gridX][gridY]->currPiece);
    //if the previous mouse on piece is neither this temp piece nor the selected piece then set the older one to idle and new one to hover
    if (tempPiece != mouseOnPiece) {
        //if the previous mouse piece is not a selected piece then we set its state to idle
        if (mouseOnPiece != nullptr && mouseOnPiece != selectedPiece) mouseOnPiece->state = PlayerPieceState::idle;

        //now mouse on piece is the latet piece
        mouseOnPiece = tempPiece;

        if (mouseOnPiece != selectedPiece) {
            mouseOnPiece->state = PlayerPieceState::hovered;
           
        }
        else {
            if (mouseOnPiece != nullptr && mouseOnPiece != selectedPiece) mouseOnPiece->state = PlayerPieceState::idle;
            mouseOnPiece = nullptr;
        }

    }
    
}

void  PlayerController::onMouseDown(){

    if(mouseOnPiece != nullptr) {
        //set the perviously selcted piece and square to idle
        if(selectedPiece != nullptr) {
            selectedPiece->state = PlayerPieceState::idle;
            selectedPiece->onSquare->overlay = SquareOverlay::idle;

            resetAvailbleMoves();
        }
                
        selectedPiece = mouseOnPiece;
        selectedPiece->state = PlayerPieceState::selected;
        selectedPiece->onSquare->overlay = SquareOverlay::selected;

        //calculate the available moves and mark thier square as available
        availableMoves = selectedPiece->CalValidMoves();

    }
    else{
        if(mouseOnSquare->overlay == SquareOverlay::available || mouseOnSquare->overlay == SquareOverlay::kill){
            movePiece(selectedPiece, mouseOnSquare);
            Board::instance().PassTurn();
        }
    }
    
            
}

void PlayerController::movePiece(PlayerPiece* playerPiece, Square* newSquare){
    //rest the square the player piece is going to move on from
    playerPiece->onSquare->currPiece = nullptr;
    playerPiece->onSquare->overlay = SquareOverlay::idle;

    //kill the piece on the square if it exists
    //this will only remove it from the draw part, since the draw on happens if (onSquare != nullptr)
    if(newSquare->currPiece) newSquare->currPiece->onSquare = nullptr;

    //move the piece
    playerPiece->onSquare = newSquare;
    newSquare->currPiece = playerPiece;

    //reset the playerpiece
    playerPiece->state = PlayerPieceState::idle;
    resetAvailbleMoves();
    selectedPiece = nullptr;
    
}

void PlayerController::DrawPieces(){

    for(auto* _piece : Pieces){
        _piece->Draw();
    }
    //string label = to_string(mouseX) + ", " + to_string(mouseY);
    //SDL_RenderDebugText(Board::instance().renderer, mouseX, mouseY, label.c_str());
}


void PlayerController::resetAvailbleMoves(){
    for(auto* square: availableMoves) square->overlay = SquareOverlay::idle; 

}

bool PlayerController::hasWon(){
    for (size_t x = 0; x < sizeof(Pieces)/sizeof(Pieces[0]); x++) if(Pieces[x]->onSquare == Board::instance().grid[x][0]) return true;
    return false;
}
