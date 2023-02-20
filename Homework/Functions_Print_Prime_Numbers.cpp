#include<iostream>
using namespace std;

bool checkPrime(int n){
    for(int i = 2; i<=n-1; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    cout << "Enter the number" << endl;
    int n;
    cin >> n;

    for(int i = 2; i <= n; i ++){
        bool isPrime = checkPrime(i);
        if(isPrime){
            cout << i << " ";
        }
    }
}