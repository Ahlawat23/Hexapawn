#include <enemyController.h>
#include<enemyPiece.h>
#include <board.h>
#include <random>

static std::random_device rd;
static std::mt19937 gen(rd());

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

    // Collect all valid moves from each enemy piece
    for(auto* _piece : Pieces) {
        std::vector<std::pair<Square*, EnemyPiece*>> moves = _piece->CalValidMoves();
        availableMoves.insert(availableMoves.end(), moves.begin(), moves.end());
    }
    // Pick one at random if there are any moves
    std::uniform_int_distribution<> dis(0, availableMoves.size() - 1);
    int randomIndex = dis(gen);
    movePiece(availableMoves[randomIndex].second, availableMoves[randomIndex].first);
    Board::instance().PassTurn();
    
}

void EnemyController::movePiece(EnemyPiece* enemyPiece, Square* newSquare){
    //rest the square the player piece is going to move on from
    enemyPiece->onSquare->currPiece = nullptr;

    //kill the piece on the square if it exists
    //this will only remove it from the draw part, since the draw on happens if (onSquare != nullptr)
    if(newSquare->currPiece) newSquare->currPiece->onSquare = nullptr;

    //move the piece
    enemyPiece->onSquare = newSquare;
    newSquare->currPiece = enemyPiece;

    //reset the enemypiece
    availableMoves.clear();
    
}

bool EnemyController::hasWon(){
    for (size_t x = 0; x < sizeof(Pieces)/sizeof(Pieces[0]); x++) if(Pieces[x]->onSquare == Board::instance().grid[x][GRID_HEIGHT-1]) return true;
    return false;
}