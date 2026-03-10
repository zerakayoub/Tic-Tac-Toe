#include "headers.h"

int main(){
    do
    {
        InitializeGame();
        while (gameOver == false)
        {
            moveCount++;
            if (moveCount > 9) {
                ClearScreen();
                PrintGrid();
                cout << "It's a draw!" << endl;
                PressEnterToContinue();
                break; // Exit the loop if the game is a draw
            }
            ClearScreen();
            PrintGrid();
            cout << "Enter your Move (1-9) or 'q' to quit." << endl;
            cout << "   Player ";
            if(player == 'X') {
                cout << YELLOW << player << RESET;
            } else {
                cout << BLUE << player << RESET;
            }
            cout << "'s turn: ";
            cin >> input;

            if (input == 'q' || input == 'Q') {
                break; // Exit the loop if the user wants to quit
            }

            // Convert input to integer for grid position
            inputToInt = input - '0'; // Convert char to int
            if (inputToInt < 1 || inputToInt > 9) {
                cout << "Invalid move! Please enter a number between 1 and 9." << endl;
                continue; // Skip to the next iteration if the move is invalid
            }

            AppendToGrid();
            CheckWin();
            ChangeTurn();
        }
        if(firstPlayer == 'X') {
            firstPlayer = 'O'; // Change first player for the next game
        } else {
            firstPlayer = 'X';
        }
        player = firstPlayer; // Reset player to the first player for the next game
        
    } while (input != 'q' && input != 'Q');

    cout << "Thanks for playing!" << endl;
    
    return 0;
}