#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<bool>Sieve(int n){
    // create a sieve array of n size, telling isPrime
    vector<bool>sieve(n+1, true);
    sieve[0] = sieve[1] = false;

    for(int i = 2; i*i <= n; i++){ // Optimisation 2
        if(sieve[i] == true){
            // Optimisation 1: First unmarked number will be i*i, as others have been marked by 2 to (i-1)
            int j = i*i;
            while(j <= n){
                sieve[j] = false;
                j+=i;
            }
        }
    }
    return sieve;
}

int main(){
    vector<bool>sieve = Sieve(25);
    for(int i = 0; i <= 25; i++){
        if(sieve[i]){
            cout << i << " ";
        }
    }
}

// TC: O(nlog(logn))