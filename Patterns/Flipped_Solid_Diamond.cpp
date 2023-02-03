#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int row = 0; row < n; row++){
        // Half pyramid
        for(int col = 0; col < n-row; col++){
            cout << "*";
        }
        for(int col = 0; col < row+1; col++){
            cout << " ";
        }
        // Space wala full pyramid
        for(int col=0; col < 2*row+1; col++){
            cout << " ";
        }

        // Half pyramid
        for(int col = 0; col < row+1; col++){
            cout << " ";
        }
        for(int col = 0; col < n-row; col++){
            cout << "*";
        }
        cout << endl;
    }
        

}