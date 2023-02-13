#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int row = 0; row < n; row ++){
        for(int col = 0; col < row+1; col++){
            if(col == 0 || row == n-1 || row == col){
                cout << col + 1;
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}