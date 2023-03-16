#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

bool isPrime(int n){

    int sqrtN = sqrt(n);
    if(n <= 1) return false;
    for(int i = 2; i <= sqrtN; i++){
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
    int n = 50;
    cout << countPrimes(n) << endl;
}

// TC: O(n*sqrt(n))