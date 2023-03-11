#include<iostream>
#include<limits.h>
using namespace std;

void findMin(int arr[], int n, int i, int& mini){
    // Base case
    if(i >= n){
        // Array agar khatm hogya (pura traverse hogya) to waps ajao
        return;
    }

    // 1 case solve krna h
    // current element ko check kro ki max h ya nhi
    mini = min(mini, arr[i]);

    // Baki recursion sambhal lega
    findMin(arr, n, i+1, mini);
}

int main(){
    int arr[8] = {10, 20, 30, 40, 50, 22, 1, 21};
    int n = 8;
    int i = 0;
    
    int mini = INT_MAX;

    findMin(arr, n, i, mini);

    cout << "Minimum number is : " << mini << endl;
}
