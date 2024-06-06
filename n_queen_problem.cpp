#include<iostream>
#include <vector>
using namespace std;

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    vector<int> temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector < vector < int > > &board, int n)
{
    int x = row;
    int y = col;

    //check for same row
    while(y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        y--;
    }

    //don't need to check for column as we're placing single queen in one row

    x = row;
    y = col;
    //check for upper diagonal
    while(x >= 0 && y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }

    x = row;
    y = col;
    //check for lower diagonal
    while(x < n && y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        x++;
        y--;
    }

    return true;
}

void solve(int col, vector<vector<int>> &ans, vector < vector < int > > &board, int n)
{
        //base case
        if(col == n){
            addSolution(ans, board, n);
            return;
        }

        //solve one case and else recursion will take care

        for(int row = 0; row < n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 1;
                solve(col+1, ans, board, n);
                //backtrack
                board[row][col] = 0;
            }
        }
}

vector< vector < int>> nQueens(int n)
{
    vector < vector < int > > board(n, vector<int>(n,0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);

    return ans;
}

void printSolution(const vector<vector<int>>& solution) {
    for (const auto& row : solution) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<int>> solutions = nQueens(n);

    if (solutions.empty()) {
        cout << "No solutions found for " << n << " queens.\n";
    } else {
        cout << "Solutions for " << n << " queens:\n";
        for (const auto& solution : solutions) {
            for (int val : solution) {
                cout << val << " ";
            }
            cout << "\n"; // Separate rows with a newline
        }
    }

    return 0;
}

