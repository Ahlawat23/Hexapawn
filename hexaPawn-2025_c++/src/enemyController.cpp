#include <enemyController.h>
#include<enemyPiece.h>
#include <board.h>
#include <random>
#include <config.h>

static std::random_device rd;
static std::mt19937 gen(rd());

EnemyController& EnemyController::instance() {
    static EnemyController singleton_instance;
    return singleton_instance;
}

EnemyController:: EnemyController(/* args */){
    //init player pieces
    for (int i = 0; i < sizeof(Pieces)/sizeof(Pieces[0]); i++) Pieces[i] = new EnemyPiece();

    //flip the coin if the enemy should be easy or hard
    bool isHard = std::uniform_int_distribution<>(0, 1)(gen) == 0;
}

void EnemyController::DrawPieces(){
    for(auto* _piece : Pieces) _piece->Draw();
}


void EnemyController::PlayMove(){
    //cal all availableMoves and then pick one at random
    if(isHard) PlayHard();
    else PlayEasy();
    
    Board::instance().PassTurn();
    
}

void EnemyController::PlayEasy(){
    std::vector<std::pair<Square*, EnemyPiece*>> availableMoves;

    // Collect all valid moves from each enemy piece
    for(auto* _piece : Pieces) {
        std::vector<std::pair<Square*, EnemyPiece*>> moves = _piece->CalForwardMove();
            availableMoves.insert(availableMoves.end(), moves.begin(), moves.end());

            moves = _piece->CalKillMoves();
            availableMoves.insert(availableMoves.end(), moves.begin(), moves.end());
    }

    if (availableMoves.empty()) {
        // No moves available,
        Board::instance().wonPlayer = 1;
        return;
    }
    // Pick one at random if there are any moves
    std::uniform_int_distribution<> dis(0, availableMoves.size() - 1);
    int randomIndex = dis(gen);
    movePiece(availableMoves[randomIndex].second, availableMoves[randomIndex].first);

}

void EnemyController::PlayHard(){

     // First, try to collect all forward moves
    std::vector<std::pair<Square*, EnemyPiece*>> forwardMoves;
    std::vector<std::pair<Square*, EnemyPiece*>> killMoves;

    for (auto* _piece : Pieces) {
        std::vector<std::pair<Square*, EnemyPiece*>> moves = _piece->CalForwardMove();
        forwardMoves.insert(forwardMoves.end(), moves.begin(), moves.end());

        moves = _piece->CalKillMoves();
        killMoves.insert(killMoves.end(), moves.begin(), moves.end());
    }
    if (!killMoves.empty()) {
        std::uniform_int_distribution<> dis(0, killMoves.size() - 1);
        int randomIndex = dis(gen);
        movePiece(killMoves[randomIndex].second, killMoves[randomIndex].first);
    }
    else if (!forwardMoves.empty()) {
        std::uniform_int_distribution<> dis(0, forwardMoves.size() - 1);
        int randomIndex = dis(gen);
        movePiece(forwardMoves[randomIndex].second, forwardMoves[randomIndex].first);
    }
          
    else {
        // No moves available
        Board::instance().wonPlayer = 1;
        return;
    }
    
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
    for(auto* _piece : Pieces)
        if(_piece->onSquare && _piece->onSquare->yIndex() == GRID_HEIGHT-1) return true;
    return false;
}