#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;

int numSquareHelper(int n){
        // Base case
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }

    int ans = INT_MAX;
    int i = 1;
    int end = sqrt(n);
    while(i <= end){
        int perfectSquares = i*i;  
        int numberOfPerfectSquares = 1 + numSquareHelper(n - perfectSquares);
        if(numberOfPerfectSquares < ans){
            ans = numberOfPerfectSquares;
        }
        ++i;
    }
    return ans;
}

int numSquares(int n){
    return numSquareHelper(n) - 1;
}

int main(){
    int n = 12;
    cout << numSquares(n) << endl;
    return 0;
}

// TC : O(n^n)
// SC : O(n)