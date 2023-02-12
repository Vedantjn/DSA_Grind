#include<iostream>
using namespace std;

void printRowWiseSUm(int arr[][3], int rows, int cols){
    // Row sum -> Row wise traversal
    cout << "Printing column wise sum: "<< endl;
    for(int i = 0; i < rows; i++){
        int sum = 0;
        for(int j = 0; j < cols; j++){
            sum = sum + arr[j][i];
        }
        cout << sum << endl;
    }

}

int main(){

    int rows, cols;
    cin >> rows >> cols;
    int arr[rows][3];


    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < cols; j ++){
            cin >> arr[i][j];
        }
    }

    printRowWiseSUm(arr, rows, cols);
}