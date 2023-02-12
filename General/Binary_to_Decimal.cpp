#include<iostream>
#include<cmath>

using namespace std;

int BinaryToDecimal(int n){
    // Bitwise method

    int decimal = 0;
    int i = 0;
    while(n){
        int bit = n%10;
        decimal = decimal + bit*pow(2, i++) ;
        n = n/10;
    }

    return decimal;
}

int main(){
    int binaryNumber;
    cin >> binaryNumber;

    cout << BinaryToDecimal(binaryNumber) << endl;

}