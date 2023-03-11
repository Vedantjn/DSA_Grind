#include<iostream>
using namespace std;

void printDigits(int n){
    // Base case
    if(n == 0){
        return;
    }

    // baaki recursion sambhal lega
    printDigits(n/10);

    // 1 case mai solve krunga
    int digit = n % 10;
    cout << digit << " ";
}

int main(){
    int n = 64700;
    if(n == 0){
        cout << 0 << endl;
    }

    printDigits(n);
}