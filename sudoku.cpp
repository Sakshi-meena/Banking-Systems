#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int val)
{
    for (int i = 0; i < board.size(); i++)
    {
        // 3 conditions for sudoku

        // case -1 check for rows -------- each row contained 1-9 numbers only 1 time
        if (board[row][i] == val)
        {
            return false;
        }
        // case -2 check for columns -------- each column contained 1-9 numbers only 1 time
        if (board[i][col] == val)
        {
            return false;
        }

        // case -3 check for 3*3 matrix -------- each 3*3 matrix contained 1-9 numbers only 1 time

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>> &board)
{
    int n = board.size();

    // traverse 9*9 matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // check if cell is empty
            if (board[row][col] == 0)
            {
                // fill values 1-9
                for (int val = 1; val <= 9; val++)
                {
                    // check if safe
                    if (isSafe(row, col, board, val))
                    {
                        board[row][col] = val; // safe to fill

                        // rest part recursion will take care
                        if (solve(board))
                        {
                            return true;
                        }
                        else
                        {
                            // backtrack
                            board[row][col] = 0;
                        }
                    }
                }
                return false; // if no valid no is found
            }
        }
    }
    return true; // sudoku is solved
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    solve(sudoku);
}

int main()
{
    vector<vector<int>> sudoku = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                                  {6, 0, 0, 1, 9, 5, 0, 0, 0},
                                  {0, 9, 8, 0, 0, 0, 0, 6, 0},
                                  {8, 0, 0, 0, 6, 0, 0, 0, 3},
                                  {4, 0, 0, 8, 0, 3, 0, 0, 1},
                                  {7, 0, 0, 0, 2, 0, 0, 0, 6},
                                  {0, 6, 0, 0, 0, 0, 2, 8, 0},
                                  {0, 0, 0, 4, 1, 9, 0, 0, 5},
                                  {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    solveSudoku(sudoku);

    // print sudoku values
    int n = sudoku.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}