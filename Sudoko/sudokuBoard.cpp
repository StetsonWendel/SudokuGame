#include "SudokuBoard.h"
//#include <iostream>
//#include <algorithm>
//#include <random>
//#include <chrono>

using namespace std;

#include <iostream>
#include <ctime>
#include <cstdlib>

SudokuBoard::SudokuBoard()
{
    generateRandomBoard();
}


// Function to print the Sudoku board
void SudokuBoard:: printBoard() 
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            std::cout << gameBoard[i][j] << " ";

            if ((((j + 1) % 3) == 0) && (j != 8))
            {
                cout << "| ";
            }
        }
        std::cout << std::endl;
        if ((((i + 1) % 3) == 0) && (i != 8))
        {
        cout << "------+-------+------" << endl;
        }
    }
    
}

// Function to generate a random Sudoku board
void SudokuBoard::generateRandomBoard() {

    // Seed the random number generator with the current time
    std::srand(std::time(nullptr));

    // Initialize the board with zeros
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            gameBoard[i][j] = 0;
        }
    }

    // Fill in the board with valid values
    for (int i = 0; i < SIZE; i += 3) 
    {
        for (int j = 0; j < SIZE; j += 3) 
        {
            // Fill in the 3x3 block with random valid values
            for (int k = 1; k <= 9; k++) 
            {
                bool isValid = true;
                int row = i + (k - 1) / 3;
                int col = j + (k - 1) % 3;

                for (int m = 0; m < SIZE; m++) 
                {
                    if (gameBoard[row][m] == k || gameBoard[m][col] == k) 
                    {
                        isValid = false;
                        break;
                    }
                }
                if (isValid) 
                {
                    gameBoard[row][col] = k;
                }
            }
        }
    }
}

// Function to validate a move in a Sudoku board
bool SudokuBoard:: validateMove( int num) 
{
    // Check if the number is already present in the same row or column
    for (int i = 0; i < SIZE - 1; i++) 
    {
        if (gameBoard[SIZE - 1][i] == num || gameBoard[i][SIZE - 1] == num) 
        {
            cout << "ConditionOne";
            return false;
        }
    }

    // Check if the number is already present in the same 3x3 block
    int startRow = (SIZE / 3) * 3;
    int startCol = (SIZE / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++) 
    {
        for (int j = startCol; j < startCol + 3; j++) 
        {
            if (gameBoard[i][j] == num) 
            {
                cout << "ConditionTwo";
                return false;
            }
        }
    }

    // The move is valid
    return true;
}


//void SudokuBoard:: generateSudokuBoard(int board[9][9]) {
//    // Seed the random number generator
//    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
//    default_random_engine rng(seed);
//
//    // Initialize the board with zeros
//    for (int row = 0; row < 9; row++) {
//        for (int col = 0; col < 9; col++) {
//            board[row][col] = 0;
//        }
//    }
//
//    // Generate random numbers for each row, column, and 3x3 block
//    for (int i = 0; i < 9; i++) {
//        // Generate random numbers for the ith row
//        for (int j = 0; j < 9; j++) {
//            int num = 0;
//            do {
//                num = uniform_int_distribution<int>{ 1, 9 }(rng);
//            } while (find(begin(board[i]), end(board[i]), num) != end(board[i]));
//            board[i][j] = num;
//        }
//
//        // Generate random numbers for the ith column
//        for (int j = 0; j < 9; j++) {
//            int num = 0;
//            do {
//                num = uniform_int_distribution<int>{ 1, 9 }(rng);
//            } while (find_if(begin(board), end(board), [&](const int(&arr)[9]) {
//                return arr[j] == num;
//                }) != end(board));
//            board[j][i] = num;
//        }
//
//        // Generate random numbers for the ith 3x3 block
//        int blockRow = (i / 3) * 3;
//        int blockCol = (i % 3) * 3;
//        for (int j = 0; j < 9; j++) {
//            int num = 0;
//            do {
//                num = uniform_int_distribution<int>{ 1, 9 }(rng);
//            } while (find_if(begin(board) + blockRow, begin(board) + blockRow + 3, [&](const int(&arr)[9]) {
//                return find(begin(arr) + blockCol, begin(arr) + blockCol + 3, num) != end(arr);
//                }) != begin(board) + blockRow + 3);
//            int row = blockRow + (j / 3);
//            int col = blockCol + (j % 3);
//            board[row][col] = num;
//        }
//    }
//}


