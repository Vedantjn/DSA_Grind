#include<iostream>
#include<vector>
using namespace std;

void printSolution(vector<vector<char>> &board, char n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
        cout << endl << endl;
}

bool isSafe(int row, int col, vector<vector<char>> &board, char n){
    // check krna chahte hain ki kya mai current cell[row][col] pr queen rakh skta hu ya nhi
    int i = row;
    int j = col;

    // check row
    while(j >= 0){
        if(board[i][j] == 'Q'){
            return false;
        }
        j--;
    }

    // check upper left diagonal
    i = row;
    j = col;
    while(i >= 0 && j >= 0){
        if(board[i][j] == 'Q'){
            return false;
        }
        i--;
        j--;
    }
    // check bottom left diagonal
    i = row;
    j = col;
    while(i < n && j >= 0){
        if(board[i][j] == 'Q'){
            return false;
        }
        i++;
        j--;
    }

    // kahin or bhi queen nhi mili
    // iska matlb position saef h
    // iska mtlb return krdo
    return true;

}

void solve(vector<vector<char>> &board, int col, char n){
    // base case
    if(col >= n){
        printSolution(board, n);
        return;
    }
    
    // ek case solvebacktracking
    for(int row = 0; row < n; row++){
        if(isSafe(row, col, board, n)){
            // rakh do
            board[row][col] = 'Q';
            // recursion solution laega
            solve(board, col+1, n);
            // backtracking
            board[row][col] = '-';
        }
    }
}

int main(){
    char n = 4;
    vector<vector<char>> board(n, vector<char>(n, '-'));
    int col = 0;
    // 0 -> empty cell
    // 1 -> queen at the cell
    solve(board, col, n);

}

// TC : O(n!)