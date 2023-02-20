#include<iostream>
using namespace std;

string EvenOrOdd(int n){
    if(n%2==0)
        return "Even";
    else
        return "Odd";
}

int main(){

    cout << "Enter the number" << endl;
    int n;
    cin >> n;

    // void result = EvenOrOdd(n);
    cout << EvenOrOdd(n) << endl;

    return 0;
}