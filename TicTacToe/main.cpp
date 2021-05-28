#include <iostream>
#include <string>
using namespace std;

char board[9] = {' ',' ', ' ',' ', ' ',' ', ' ',' ',' '};
void ShowBoard();


void ShowBoard() {
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board [0] << "  |   " << board[1] << "  |   " << board[2] << endl;
    cout << "--------------------" << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board [3] << "  |   " << board[4] << "  |   " << board[5] << endl;
    cout << "--------------------" << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board [6] << "  |   " << board[7] << "  |   " << board[8] << endl;
}