#include <iostream>

using namespace std;

int main() {
    int num, sticks, SecondPlayer;

    bool winner = false;

    cout << "This is a Game of Nim! Please enter a number between 1 to 3\n" << endl;
    cin >> sticks;

    while(sticks < 1 || sticks > 3 || sticks > num);
    cout << "You have entered a wrong number\n"
    << "Enter a number between 1 to 3 please!" << endl;
    cin >> sticks;

}
