#include<iostream>
#include<limits.h>
using namespace std;

void findMax(int arr[], int n, int i, int& maxi){
    // Base case
    if(i >= n){
        // Array agar khatm hogya (pura traverse hogya) to waps ajao
        return;
    }

    // 1 case solve krna h
    // current element ko check kro ki max h ya nhi
    maxi = max(maxi, arr[i]);

    // Baki recursion sambhal lega
    findMax(arr, n, i+1, maxi);
}

int main(){
    int arr[8] = {10, 20, 30, 40, 50, 22, 1, 21};
    int n = 8;
    int i = 0;
    
    int maxi = INT_MIN;

    findMax(arr, n, i, maxi);

    cout << "Maximum number is : " << maxi << endl;
}
