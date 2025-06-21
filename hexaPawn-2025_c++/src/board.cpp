#include<board.h>
#include <iostream>
#include <SDL3/SDL.h>

using namespace std;

Board::Board(){
    data = 0;
    cout << "data " << data ;
}

void Board::Draw(){
    data = 23;
    cout << "data " << data ;
}

void Board::onceDragIsDonePlayTheEnemy(){
    data = 23;
    cout << "data " << data ;
}