#include<iostream>
#include<cmath>

using namespace std;

int decimalToBinary(int n){
    // Division method

    int binaryNumber = 0;
    int i = 0;
    while(n>0){
        int bit = n%2;
        binaryNumber = bit*pow(10, i++) + binaryNumber;
        n = n/2;
    }
    return binaryNumber;
}

int main(){
    int n;
    cin >> n;

    int binary = decimalToBinary(n);
    cout << binary << endl;

}