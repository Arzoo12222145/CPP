#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> board, int val)
{
    for(int i = 0; i < board.size(); i++){
        //check row
        if(board[row][i] == val){
            return false;
        }
        //check col
        if(board[i][col] == val){
            return false;
        }
    }
    //check 3*3 matrix
    int startRow = 3*(row/3);
    int startCol = 3*(col/3);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[startRow + i][startCol + j] == val){
                return false;
            }
        }
    }
    return true;
}

bool solve(vector<vector<int>>& board)
{
    int n = board[0].size();

    for(int row = 0; row < n; row++){

        for(int col = 0; col < n; col++){

            //check for empty cell
            if(board[row][col] == 0){
                for(int val= 1; val <= 9; val++){
                    if(isSafe(row, col, board, val)){
                        board[row][col] = val;

                        //recursive call
                        if(solve(board)){
                            return true;
                        }
                        else{
                            board[row][col] = 0;
                        }
                    }
                }
                return false; //if tried all values and solution not found which means solution is not possible;
            }
        }
    }

    return true;  // solution found
}

void solveSudoku(vector<vector<int>>& board)
{
    if(solve(board)){
        cout << "Solved Sudoku:\n";
        for (const auto& row : board) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "No solution found for the given Sudoku board.\n";
    }
}

int main() {
    int n = 9; // Assuming standard 9x9 Sudoku board

    vector<vector<int>> board(n, vector<int>(n));
    cout << "Enter the Sudoku board (0 for empty cells):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    solveSudoku(board);

    return 0;
}
