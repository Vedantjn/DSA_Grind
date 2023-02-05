#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int row = 0; row < n; row++){
        int start = 1;
        for(int col = 0; col < row+1; col++){
            cout << start;
            start++;
        }
        cout << endl;
    }
}
