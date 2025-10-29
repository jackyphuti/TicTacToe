// TicTacToeHelper.h
#ifndef TICTACTOEHELPER_H
#define TICTACTOEHELPER_H

#include <string>
using namespace std;

string generateEmptyBoard();
char getCell(string board, int cellIndex);
string makeMove(string board, int position, char symbol);
string prettyPrint(string board);
bool isValidMove(string board, int cell);
bool isInValidMove(string board, int cell);
bool isPlayerTurn(int turnCount, char symbol);
bool isPlayerATurn(int turnCount);
bool isPlayerBTurn(int turnCount);
bool rowCheck(string board, int row, char symbol);
bool colCheck(string board, int col, char symbol);
bool checkAllRows(string board, char symbol);
bool checkAllCols(string board, char symbol);
bool upwardDiagonalCheck(string board, char symbol);
bool downwardDiagonalCheck(string board, char symbol);
bool isAWinner(string board);
bool isBWinner(string board);
bool boardFull(string board);
bool gameOver(string board);

#endif // TICTACTOEHELPER_H