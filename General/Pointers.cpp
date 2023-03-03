#include<iostream>
using namespace std;

int main(){

    int a = 5;
    int *p = &a;
    int *q = p;
    int *r = q;
    
    cout << a << endl; // value of a
    cout << &a << endl; // address of a
    cout << p << endl; // value stored in p
    cout << *p << endl; // value of address stored in p
    cout << &p << endl; // address of p
    cout << q << endl; // value stored in q
    cout << &q << endl; // address of q
    cout << *q << endl; // value of address stored in q
    cout << r << endl; // value stored in r
    cout << *r << endl; // value of address stored in r
    cout << &r << endl; // address of r

}