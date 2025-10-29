// TicTacToeHelper.cpp
#include "TicTacToeHelper.h"
#include <iostream>
#include <string>

using namespace std;

// Returns an empty Tic-Tac-Toe board as a string
string generateEmptyBoard() {
    return "         "; // 9 space characters
}

// Returns the character at the given index of the board
char getCell(string board, int cellIndex) {
    return board[cellIndex];
}

// Places a symbol at the given position and returns the updated board
string makeMove(string board, int position, char symbol) {
    if (position >= 0 && position < 9) {
        board[position] = symbol;
    }
    return board;
}

// Formats and prints the board
string prettyPrint(string board) {
    return string(1, board[0]) + "|" + board[1] + "|" + board[2] + "\n" +
           "-+-+-\n" +
           string(1, board[3]) + "|" + board[4] + "|" + board[5] + "\n" +
           "-+-+-\n" +
           string(1, board[6]) + "|" + board[7] + "|" + board[8] + "\n";
}

// Checks if a move is valid (i.e., the cell is empty)
bool isValidMove(string board, int cell) {
    return cell >= 0 && cell < 9 && board[cell] == ' ';
}

// Checks if a move is invalid (i.e., the cell is occupied)
bool isInValidMove(string board, int cell) {
    return cell < 0 || cell >= 9 || board[cell] != ' ';
}

// Determines if it is a specific player's turn based on turn count
bool isPlayerTurn(int turnCount, char symbol) {
    return (turnCount % 2 == 0 && symbol == '0') || (turnCount % 2 == 1 && symbol == '1');
}

bool isPlayerATurn(int turnCount) {
    return turnCount % 2 == 0;
}

bool isPlayerBTurn(int turnCount) {
    return turnCount % 2 == 1;
}

// Checks if all three cells in a row match the given symbol
bool rowCheck(string board, int row, char symbol) {
    if (row >= 0 && row < 3)
        return board[row * 3] == symbol && board[row * 3 + 1] == symbol && board[row * 3 + 2] == symbol;
    return false;
}

// Checks if all three cells in a column match the given symbol
bool colCheck(string board, int col, char symbol) {
    if (col >= 0 && col < 3)
        return board[col] == symbol && board[col + 3] == symbol && board[col + 6] == symbol;
    return false;
}

// Checks if any row contains a winning line
bool checkAllRows(string board, char symbol) {
    return rowCheck(board, 0, symbol) || rowCheck(board, 1, symbol) || rowCheck(board, 2, symbol);
}

// Checks if any column contains a winning line
bool checkAllCols(string board, char symbol) {
    return colCheck(board, 0, symbol) || colCheck(board, 1, symbol) || colCheck(board, 2, symbol);
}

// Checks the upward diagonal for a win
bool upwardDiagonalCheck(string board, char symbol) {
    return board[6] == symbol && board[4] == symbol && board[2] == symbol;
}

// Checks the downward diagonal for a win
bool downwardDiagonalCheck(string board, char symbol) {
    return board[0] == symbol && board[4] == symbol && board[8] == symbol;
}

// Checks if player A has won
bool isAWinner(string board) {
    return checkAllRows(board, '0') || checkAllCols(board, '0') || downwardDiagonalCheck(board, '0') || upwardDiagonalCheck(board, '0');
}

// Checks if player B has won
bool isBWinner(string board) {
    return checkAllRows(board, '1') || checkAllCols(board, '1') || downwardDiagonalCheck(board, '1') || upwardDiagonalCheck(board, '1');
}

// Checks if the board is full
bool boardFull(string board) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') return false;
    }
    return true;
}

// Checks if the game is over
bool gameOver(string board) {
    return isAWinner(board) || isBWinner(board) || boardFull(board);
}
