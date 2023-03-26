#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int value, int board[][9], int curr_row, int curr_col){
    // Row check
    for(int col = 0; col < 9; col++){
        if(board[curr_row][col] == value){
            return false;
        }
    }

    // Column check
    for(int row = 0; row < 9; row++){
        if(board[row][curr_col] == value){
            return false;
        }
    }

    // 3x3 check
    for(int i = 0; i < 9; i++){
        if(board[3*(curr_row/3) + (i/3)][3*(curr_col/3) + (i%3)] == value){
            return false;
        }
    }

    return true;
}

// This function returns true or false based on we found a solution or not
bool solve(int board[9][9], int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // check for empty cell
            if(board[i][j] == 0){
                for(int value = 1; value <= 9; value++){
                    // chack for safety
                    if(isSafe(value, board, i, j)){
                        // insert
                        board[i][j] = value;
                        // baki recursion sambhal lega
                        bool aageKaSolition = solve(board, n);
                        if(aageKaSolition == true){
                            return true;
                        }
                        // Backtracking
                        board[i][j] = 0;
                    }
                }
            }

        }
    }
    return false;
}

int main(){
    // 0 -> represents an empty cell
    int board[9][9] = { {4, 5, 0,0,0,0,0,0},
    

    };

    int n = 9;

    solve(board, n);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 0; j++){
            cout << board[i][j] << " ";
        }
    }

    return 0;
}