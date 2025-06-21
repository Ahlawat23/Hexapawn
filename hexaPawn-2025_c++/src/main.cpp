
#include <iostream>

#include "board.h"

using namespace std;


int main(int argc, char* argv[]){
    Board man;
    man.Draw();

    cout << "Press Enter to exit...";
    cin.get();
    return 0;
}
