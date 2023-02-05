#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    for(int row = 0; row < n; row++){
        // Spaces
        for(int col = 0; col < n-row-1; col++){
            cout << " ";
        }
        // Numbers
        for(int col = 0; col < row+1; col++){
            cout << row+col+1;
        }
        // Reverse counting
        int start = 2*row;
        for(int col = 0; col < row; col++){
            cout << start;
            start--;
        }
        cout << endl;
    }
}