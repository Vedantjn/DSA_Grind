#include<iostream>
using namespace std;

int slowExponentiation(int a, int b){
    int ans = 1;
    for(int i = 0; i<b; i++){
        ans = ans*a;
    }
    return ans;
}

int main(){
    cout << slowExponentiation(5, 4);
}

// TC: O(b)