#include<iostream>
#include<limits.h>
using namespace std;

void transpose(int arr[][3], int rows, int cols, int transposeArray[][3]){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            // swap(arr[i][j], arr[j][i]);
            transposeArray[j][i] = arr[i][j];
        }
    }
}

void printMatrix(int arr[][3], int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){

    int rows, cols;
    cin >> rows >> cols;
    int arr[rows][3];
    
    int transposeArray[3][3];

    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < cols; j ++){
            cin >> arr[i][j];
        }
    }

    transpose(arr, rows, cols, transposeArray);
    printMatrix(transposeArray, rows, cols);
}