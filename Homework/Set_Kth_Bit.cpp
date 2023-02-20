#include<iostream>
using namespace std;

int kthBit(int n, int k){
    int mask = 1 << k;
    int ans = n | mask;
    return ans;
}

int main(){
    int n, k;
    cin >> n >> k;

    cout << kthBit(n, k);
}