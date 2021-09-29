#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Solution
{
public:
    int getSquareIndex(int row, int column)
    {
        //find square index
        return row / 3 * 3 + column / 3;
    }

    bool backtrackingSudoku(vector<vector<char>> &board,
                            vector<vector<bool>> &isRow,
                            vector<vector<bool>> &isColumn,
                            vector<vector<bool>> &isSquare,
                            int index)
    {
        if (index >= 81)
            //fill finished
            return true;

        int rowIndex = index / 9;
        int columnIndex = index % 9;
        if (board[rowIndex][columnIndex] != '.')
            return backtrackingSudoku(board, isRow, isColumn, isSquare, index + 1);

        int squareIndex = getSquareIndex(rowIndex, columnIndex);
        for (int i = 1; i <= 9; ++i)
        {
            //detect whether i(this number) exist
            if (isRow[rowIndex][i] ||
                isColumn[columnIndex][i] ||
                isSquare[squareIndex][i])
                //loop continue
                //the following code will not execute
                continue;

            board[rowIndex][columnIndex] = i + '0';
            isRow[rowIndex][i] = true;
            isColumn[columnIndex][i] = true;
            isSquare[squareIndex][i] = true;

            if (backtrackingSudoku(board, isRow, isColumn, isSquare, index + 1))
                //means finish
                return true;

            //this number is illegal return fill '.'
            board[rowIndex][columnIndex] = '.';
            isRow[rowIndex][i] = false;
            isColumn[columnIndex][i] = false;
            isSquare[squareIndex][i] = false;
        }

        return false;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        vector<vector<bool>> isRow(9, vector<bool>(10, false));
        vector<vector<bool>> isColumn(9, vector<bool>(10, false));
        vector<vector<bool>> isSquare(9, vector<bool>(10, false));

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == '.')
                    continue;

                int number = board[i][j] - '0';
                isRow[i][number] = true;
                isColumn[j][number] = true;
                isSquare[getSquareIndex(i, j)][number] = true;
            }
        }

        backtrackingSudoku(board, isRow, isColumn, isSquare, 0);
    }
};

int main(){
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution sol;
    sol.solveSudoku(board);
    printf("end");
}
/*******************************************************/
/* LeetCode 37. Sudoku Solver                          */
/* Author: Maplewing [at] knightzone.studio            */
/* Version: 2019/04/01                                 */
/*******************************************************/
//Ref and study Maplewing [at] knightzone.studio 's code
//Runtime: 4 ms, faster than 97.05% of C++ online submissions for Sudoku Solver.
//Memory Usage: 6.6 MB, less than 23.73% of C++ online submissions for Sudoku Solver.