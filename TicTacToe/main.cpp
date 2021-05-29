#include <iostream>
#include <ctime>
#include <random>

using namespace std;

char board[9] = {' ',' ', ' ',' ', ' ',' ', ' ',' ',' '};
void ShowBoard();
void GetXPlayersChoice();
void GetOPlayersChoice();
void GetComputerChoice();
int CountBoard(char symbol);
char CheckWinner();
void ComputerVsPlayers();
void PlayerVsPlayers();

int main(){
    ComputerVsPlayers();
    CheckWinner();

}

void ComputerVsPlayers()
{
    char PlayersName [20];
    cout << "Enter your name: ";
    cin >> PlayersName;
    while(true)
    {
        system("cls");
        ShowBoard();
        if(CountBoard('X') == CountBoard('O'))
        {
            cout << PlayersName << "'s turn" << endl;
            GetXPlayersChoice();
        }
        else
        {
            GetComputerChoice();
        }
        char winner = CheckWinner();
        if (winner == 'X') {
            system("cls");
            ShowBoard();
            cout << PlayersName << "Won the game." << endl;
            break;
        }
        else if (winner == 'O')
        {
            system ("cls");
            ShowBoard();
            cout << "Computer won the game." << endl;
            break;
        }
        else if (winner == 'D'){
            cout << "Game is Draw." << endl;
            break;
        }
    }

}

void GetComputerChoice()
{
    srand(time (0));
    int Choice;
    do {
        Choice = rand()%10;
    } while (board [Choice] != ' ');
      board [Choice] = 'O';
}

void GetXPlayersChoice(){
    while (true){
        cout << "sleect your position (1-9): ";
        int Choice;
        cin >> Choice;
        Choice --;// This will lower the count by 1, because counting always start from 0
        if(Choice < 0 || Choice > 8) {
            cout <<  "Please select your choice from (1-9)." << endl;
        }
        else if(board[Choice] != ' ') {
            cout << "Please select an empty position." << endl;
        } else {
            board[Choice] = 'X';
            break;
        }
    }
}

void GetOPlayersChoice(){
    while (true)
    {
        cout << "sleect your position (1-9): ";
        int Choice;
        cin >> Choice;
        Choice --;// This will lower the count by 1, because counting always start from 0
        if(Choice < 0 || Choice > 8) {
            cout <<  "Please select your choice from (1-9)." << endl;
        }
        else if(board[ Choice] != ' ')
        {
            cout << "Please select an empty position." << endl;
        } else
        {
            board[Choice] = 'O';
            break;
        }
    }
}

int CountBoard(char symbol)
{
    int total = 0;
    for(int i=0; i<9; i++){
        if(board [i] == symbol)
            total += 1;
    }
    return total;
}

char CheckWinner()
{
    // checking for winner in horizontal/row
    if(board [0] == board [1] && board [1] == board [2] && board [0] !=' ')
        return board [0];
    if(board [3] == board [4] && board [4] == board [5] && board [3] !=' ')
        return board [3];
    if(board [6] == board [7] && board [7] == board [8] && board [6] !=' ')
        return board [6];
    // checking for winner in vertical/column
    if(board [0] == board [3] && board [3] == board [6] && board [0] !=' ')
        return board[0];
    if(board [1] == board [4] && board [4] == board [7] && board [1] !=' ')
        return board[1];
    if(board [2] == board [5] && board [5] == board [8] && board [2] !=' ')
        return board[2];
    // checking for winner in diagonal
    if(board [0] == board [4] && board [4] == board [8] && board [0] !=' ')
        return board[0];
    if(board [2] == board [4] && board [4] == board [6] && board [2] !=' ')
        return board[2];
    if(CountBoard('X') + CountBoard('O') < 9)
        return 'C'; // continue
    else
        return 'D'; // Draw

}

void ShowBoard() {
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board [0] << "  |   " << board[1] << "  |   " << board[2] << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "--------------------" << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board [3] << "  |   " << board[4] << "  |   " << board[5] << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "--------------------" << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board [6] << "  |   " << board[7] << "  |   " << board[8] << endl;
    cout << "   " << "   |   " << "   |   " << endl;
}