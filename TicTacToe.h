#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>

std::string generateEmptyBoard();
std::string prettyPrint(std::string board);
int playGame();

int askPlayerForPosition(std::string board, char symbol);


#endif /*TICTACTOE_H*/