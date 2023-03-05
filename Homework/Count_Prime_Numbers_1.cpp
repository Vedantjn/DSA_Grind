#include<iostream>
#include<algorithm>
using namespace std;

bool isPrime(int n){

    if(n <= 1) return false;
    for(int i = 2; i < n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int countPrimes(int n){
    
    int count = 0;
    for(int i = 0; i < n; i++){
        if(isPrime(i)){
            count++;
        }
    }
    return count;
}

int main(){
    int n = 500000;
    cout << countPrimes(n) << endl;
}

// TC: O(n)