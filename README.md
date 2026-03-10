# Tic-Tac-Toe (C++ Console Game)

## Overview

This project is a **console-based Tic-Tac-Toe game written in C++** that allows two players to compete against each other in a turn-based match.

The program displays a formatted game board in the terminal, allows players to choose positions, checks for win conditions, and detects draws. The game also includes colored console output to improve readability.

This project demonstrates core C++ concepts such as **arrays, control flow, user input handling, modular functions, and game state management**.

---

## Features

### Core Gameplay

- Two-player Tic-Tac-Toe
- Turn-based gameplay
- Win detection for:
  - Rows
  - Columns
  - Diagonals
- Automatic draw detection
- Input validation for illegal moves
- Option to quit the game

### Game Interface

- Clean console board layout
- Colored player symbols using ANSI escape codes
- Clear prompts for player turns
- Dynamic board updates after each move

Players are represented by:

- **X** (yellow)
- **O** (blue)

---

## Technologies Used

- **C++**
- Arrays
- Console input/output (`iostream`)
- Modular program design
- ANSI escape codes for terminal colors

---

## Project Structure

```
TicTacToe/

│
├── main.cpp
├── headers.h
└── Tik-Tac-Toe.exe
```

### main.cpp

Handles:

- Main game loop
- Player input
- Game restart logic

### headers.h

Contains the core game logic including:

- Board initialization
- Board rendering
- Win detection
- Player turn management
- Input validation
- Screen clearing

---

## How the Game Works

### 1. Board Initialization

The board is represented as a **5×5 character grid** to include both playable cells and visual separators.

Example board layout:

```
1 | 2 | 3
4 | 5 | 6
7 | 8 | 9
```

Each number represents a selectable position on the board.

---

### 2. Player Turns

Players alternate turns between **X** and **O**.

Example prompt:

```
Enter your Move (1-9) or 'q' to quit.

Player X's turn:
```

---

### 3. Move Validation

The program checks:

- Whether the input is between **1–9**
- Whether the chosen cell is already occupied

Invalid moves prompt the user to try again.

---

### 4. Win Detection

The program checks for wins across:

- Horizontal rows
- Vertical columns
- Diagonals

Example win message:

```
Player X wins!
```

---

### 5. Draw Detection

If **9 moves occur without a winner**, the game ends with a draw.

```
It's a draw!
```

---

## Running the Program

### Compile

```bash
g++ main.cpp -o tictactoe
```

### Run

```bash
./tictactoe
```

Or run the included executable:

```
Tik-Tac-Toe.exe
```

---

## Example Gameplay

```
Tic-Tac-Toe

1 | 2 | 3
4 | 5 | 6
7 | 8 | 9

Enter your Move (1-9)

Player X's turn: 5
```

---

## Concepts Demonstrated

- Game state management
- Turn-based logic
- Input validation
- 2D arrays
- Modular program design
- Console UI formatting

---

## Future Improvements

Possible enhancements include:

- Single-player mode with AI
- Minimax algorithm for optimal moves
- Score tracking between rounds
- GUI version using a graphics library
- Online multiplayer support
