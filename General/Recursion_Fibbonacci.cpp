#include<iostream>
using namespace std;

// Fibonacci series: 0 1 1 2 3 5 8 ....

int fib(int n){
    // Base case
    if(n == 1) // First term
        return 0;
    if(n == 2) // Second term
        return 1;

    // Recursive call
    int ans = fib(n-1) + fib(n-2);
    return ans;
}

int main(){
    int n;
    cout << "Enter the term you want to see "<< endl;
    cin >> n;

    int ans = fib(n);
    cout << "The " << n << "th term is: " << ans <<endl;
}