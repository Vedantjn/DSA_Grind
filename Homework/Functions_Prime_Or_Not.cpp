#include<iostream>
using namespace std;

string PrimeOrNot(int n){
    for(int i = 2; i<=n-1; i++){
        if(n%i==0){
            return "Not Prime";
        }
        else{
            return "Prime";
        }
    }
}

int main(){
    cout << "Enter the number" << endl;
    int n;
    cin >> n;

    cout << "The number " << n << " is " << PrimeOrNot(n) << endl;
}