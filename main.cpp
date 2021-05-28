#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{


    int num_objects = 24;
    int current_player = 1;
    int sticks;



    do {
        if (current_player == 1) {
            cout << "This is a Game of Nim! Please enter a number between 1 to 3\n ";
            cin >> sticks;

            while (sticks < 1 || sticks > 3 || sticks > num_objects) {
                cout << "You have entered the wrong number\n Enter a number between 1 to 3: ";
                cin >> sticks;
            }
        }
        else {             // COMPUTER turn
            do {
                sticks = 1 + rand() % 3;  // random computer turn
            } while (sticks < 1 || sticks > 3 || sticks > num_objects);
            cout << "Computer removed " << sticks << "from the pile" << endl;
        }
        num_objects -= sticks;    // REMOVE the objects from the heap
        cout << num_objects << " objects remaining." << endl;
        current_player = (current_player + 1) % 2;
    } while (num_objects > 0);

    //End of the game loop

    cout << "Player " << current_player << " wins!!!" << endl;

    cin.ignore();
    cout << "\nPress enter to quit.\n";
    cin.ignore();
    return 0;
}