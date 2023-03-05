#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int countPrimes(int n){

    if(n==0) return 0;

    vector<bool>prime(n, true); // all elements marked prime
    prime[0] = prime[1] = false;

    int ans = 0;
    for(int i = 2; i < n; i++){
        if(prime[i]){
            ans++;

            int j = 2*i;
            while(j<n){
                prime[j] = false;
                j+=i;
            }
        }
    }
    return ans;
}

int main(){
    int n = 500000;
    cout << countPrimes(n) << endl;
}

// TC: O(n*log(log(n)))