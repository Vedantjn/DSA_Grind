#include<iostream>
using namespace std;

void printCounting(int n){
    // Base case
    if(n == 0)
        return;
    
    // Processing
    cout << n << endl;

    // Recursive call
    printCounting(n-1);
}

int main(){
    int n;
    cin >> n;

    printCounting(n);
    cout << endl;
}