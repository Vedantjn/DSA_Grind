#include<iostream>
using namespace std;

int binaryToDecimal(int b){
    int ans=0;
    int c=0;
    while(b){
        ans=ans+(b % 10) * (1 << c++);
        b/=10;
    }
    return ans;
}

int main(){

    int b;
    cin >> b;

    cout << binaryToDecimal(b);
}