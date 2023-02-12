#include<iostream>
#include<limits.h>
using namespace std;

void getMinMax(int arr[][3], int rows, int cols){
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(arr[i][j] > maxi)
                maxi = arr[i][j];
            if(arr[i][j] < mini)
                mini = arr[i][j];
        }
    }
    cout<<mini<<' '<<maxi<<'\n';
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

    getMinMax(arr, rows, cols);
}