#pragma once
#include <iostream>

using namespace std;

void InitializeGame();
void PrintGrid();
void ClearScreen();
void CheckWin();
void AppendToGrid();
void ChangeTurn();
void PressEnterToContinue();

const string BOLD = "\033[1m"; // ANSI escape code for bold text
const string RESET = "\033[0m"; // ANSI escape code to reset text formatting
const string YELLOW = "\033[33m"; // ANSI escape code for yellow text
const string BLUE = "\033[34m"; // ANSI escape code for blue text

char grid[5][5];
char input;
char player = 'X'; // Default player symbol
bool gameOver;
int inputToInt;
int moveCount;
char firstPlayer = 'X'; // Default first player symbol

void InitializeGame(){
	char temp[5][5] = {
		{'1', '|', '2', '|', '3'},
        {'-', '|', '-', '|', '-'},
        {'4', '|', '5', '|', '6'},
		{'-', '|', '-', '|', '-'},
		{'7', '|', '8', '|', '9'},
	};
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			grid[i][j] = temp[i][j];
		}
	}
    gameOver = false; // Reset game over status
    moveCount = 0; // Reset move count
}

void PrintGrid(){
    const int padding = 13; // Padding for the title
    const int boardPadding = 15;

    cout << BOLD << string(padding, '-') << YELLOW << " Tic" << RESET << BOLD << '-' << RESET;
    cout << BOLD << YELLOW << "Tac" << RESET << BOLD << '-' << RESET;
    cout << BOLD << YELLOW << "Toe " << RESET;
    cout << BOLD << string(padding, '-') << RESET << endl;
    cout << endl;
    for(int i = 0; i < 5; i++){
        cout << string(boardPadding, ' ');
        for(int j = 0; j < 5; j++){
            if(grid[i][j] == 'X'){
                cout << BOLD << YELLOW << grid[i][j] << RESET << " ";
            } else if(grid[i][j] == 'O'){
                cout << BOLD << BLUE << grid[i][j] << RESET << " ";
            } else {
                cout << BOLD << grid[i][j] << " " << RESET;
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << BOLD << string(39, '-') << RESET << endl;

}

void CheckWin(){
    if(grid[0][0] == grid[0][2] && grid[0][2] == grid[0][4]) {              // Check first row
        ClearScreen();
        PrintGrid();
        cout << "Player " << YELLOW << grid[0][0] << RESET << " wins!" << endl;
        gameOver = true;
        PressEnterToContinue();
    } else if(grid[2][0] == grid[2][2] && grid[2][2] == grid[2][4]) {       // Check third row
        ClearScreen();
        PrintGrid();
        cout << "Player " << YELLOW << grid[2][0] << RESET << " wins!" << endl;
        gameOver = true;
        PressEnterToContinue();
    } else if(grid[4][0] == grid[4][2] && grid[4][2] == grid[4][4]) {       // Check fifth row
        ClearScreen();
        PrintGrid();
        cout << "Player " << YELLOW << grid[4][0] << RESET << " wins!" << endl;
        gameOver = true;
        PressEnterToContinue();
    } else if(grid[0][0] == grid[2][0] && grid[2][0] == grid[4][0]) {       // Check first column
        ClearScreen();
        PrintGrid();
        cout << "Player " << YELLOW << grid[0][0] << RESET << " wins!" << endl;
        gameOver = true;
        PressEnterToContinue();
    } else if(grid[0][2] == grid[2][2] && grid[2][2] == grid[4][2]) {       // Check third column
        ClearScreen();
        PrintGrid();
        cout << "Player " << YELLOW << grid[0][2] << RESET << " wins!" << endl;
        gameOver = true;
        PressEnterToContinue();
    } else if(grid[0][4] == grid[2][4] && grid[2][4] == grid[4][4]) {       // Check fifth column
        ClearScreen();
        PrintGrid();
        cout << "Player " << YELLOW << grid[0][4] << RESET << " wins!" << endl;
        gameOver = true;
        PressEnterToContinue();
    } else if(grid[0][0] == grid[2][2] && grid[2][2] == grid[4][4]) {       // Check diagonal
        ClearScreen();
        PrintGrid();
        cout << "Player " << YELLOW << grid[0][0] << RESET << " wins!" << endl;
        gameOver = true;
        PressEnterToContinue();
    } else if(grid[0][4] == grid[2][2] && grid[2][2] == grid[4][0]) {       // Check anti-diagonal
        ClearScreen();
        PrintGrid();
        cout << "Player " << YELLOW << grid[0][4] << RESET << " wins!" << endl;
        gameOver = true;
        PressEnterToContinue();
    } else {
        return;
    }
}

void AppendToGrid(){
    switch(inputToInt) {
        case 1: 
            if(grid[0][0] == 'X' || grid[0][0] == 'O'){
                cout << "Invalid move! Cell already taken." << endl;
                PressEnterToContinue();
                ChangeTurn(); // Change turn if the move is invalid
                moveCount--; // Decrement move count to allow retry
                break;
            } else {
                grid[0][0] = player; break;
            }
        case 2: 
            if(grid[0][2] == 'X' || grid[0][2] == 'O'){
                cout << "Invalid move! Cell already taken." << endl;
                PressEnterToContinue();
                ChangeTurn(); // Change turn if the move is invalid
                moveCount--; // Decrement move count to allow retry
                break;
            } else {
                grid[0][2] = player; break;
            }
        case 3: 
            if(grid[0][4] == 'X' || grid[0][4] == 'O'){
                cout << "Invalid move! Cell already taken." << endl;
                PressEnterToContinue();
                ChangeTurn(); // Change turn if the move is invalid
                moveCount--; // Decrement move count to allow retry
                break;
            } else {
                grid[0][4] = player; break;
            }
        case 4: 
            if(grid[2][0] == 'X' || grid[2][0] == 'O'){
                cout << "Invalid move! Cell already taken." << endl;
                PressEnterToContinue();
                ChangeTurn(); // Change turn if the move is invalid
                moveCount--; // Decrement move count to allow retry
                break;
            } else {
                grid[2][0] = player; break;
            }
        case 5: 
            if(grid[2][2] == 'X' || grid[2][2] == 'O'){
                cout << "Invalid move! Cell already taken." << endl;
                PressEnterToContinue();
                ChangeTurn(); // Change turn if the move is invalid
                moveCount--; // Decrement move count to allow retry
                break;
            } else {
                grid[2][2] = player; break;
            }
        case 6: 
            if(grid[2][4] == 'X' || grid[2][4] == 'O'){
                cout << "Invalid move! Cell already taken." << endl;
                PressEnterToContinue();
                ChangeTurn(); // Change turn if the move is invalid
                moveCount--; // Decrement move count to allow retry
                break;
            } else {
                grid[2][4] = player; break;
            }
        case 7: 
            if(grid[4][0] == 'X' || grid[4][0] == 'O'){
                cout << "Invalid move! Cell already taken." << endl;
                PressEnterToContinue();
                ChangeTurn(); // Change turn if the move is invalid
                moveCount--; // Decrement move count to allow retry
                break;
            } else {
                grid[4][0] = player; break;
            }
        case 8: 
            if(grid[4][2] == 'X' || grid[4][2] == 'O'){
                cout << "Invalid move! Cell already taken." << endl;
                PressEnterToContinue();
                ChangeTurn(); // Change turn if the move is invalid
                moveCount--; // Decrement move count to allow retry
                break;
            } else {
                grid[4][2] = player; break;
            }
        case 9: 
            if(grid[4][4] == 'X' || grid[4][4] == 'O'){
                cout << "Invalid move! Cell already taken." << endl;
                PressEnterToContinue();
                ChangeTurn(); // Change turn if the move is invalid
                moveCount--; // Decrement move count to allow retry
                break;
            } else {
                grid[4][4] = player; break;
            }
        default: cout << "Invalid position!" << endl; return;
    }
}

void ChangeTurn(){
    if(player == 'X') {
        player = 'O';
    } else {
        player = 'X';
    }
}

void PressEnterToContinue(){
    cout << "Press " << YELLOW << "Enter" << RESET << " to continue..." << endl;
    cin.ignore(); // Ignore any leftover newline character in the input buffer
    cin.get(); // Wait for user to press Enter
}

void ClearScreen(){
    system("cls");
}