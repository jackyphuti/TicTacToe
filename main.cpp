#include <iostream>
#include <fstream>
#include <string>
#include "TicTacToe.h"
#include "TicTacToeHelper.h"

using namespace std;

int main()
{
    std::ifstream infile("board.txt");
    std::string board;
    if (infile) {
        std::getline(infile, board);
    } else {
        board = generateEmptyBoard();
    }

    std::cout << "Board:\n" << prettyPrint(board) << std::endl;  
    return 0;
}
