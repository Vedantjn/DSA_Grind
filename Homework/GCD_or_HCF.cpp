#include<iostream>
using namespace std;

// GCD(a, b) = GCD(a-b, b) if a>b
// GCD(a, b) = GCD(b-a, a) if b>a

int gcd(int A, int B){
    
    if(A == 0) return B;
    if(B == 0) return A;

    while(A>0 && B>0){
        if(A>B){
            A = A-B;
        }
        else{
            B = B-A;
        }
    }    
    return A == 0 ? B : A;
}

int main(){

    int A = 3;
    int B = 6;

    cout << gcd(A, B) << endl;
}