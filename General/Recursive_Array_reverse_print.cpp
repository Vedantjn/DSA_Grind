#include<iostream>
using namespace std;

void print(int arr[], int n, int i){
    // Base case
    if(i >= n){
        return;     // i array k size k andar hi hona chaie, out of bound ni hona chaie
    }

    // Recursive call
    print(arr, n, i+1);

    // Processing -> ek case solve kr dia
    cout << arr[i] << " ";
}

int main(){
    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;
    int i = 0;
    print(arr, n, i);
}
