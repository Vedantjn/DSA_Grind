#include<iostream>
using namespace std;

long long int Factorial(long long int n){
    long long int f = 1;
    for(int a = n; a >=1; a--){
        f = f*a;
    }
    return f;
}

int main(){
    cout << "Enter the number" << endl;
    int n;
    cin >> n;

    cout << "The factorial of " << n << " is " << Factorial(n) << endl;
}