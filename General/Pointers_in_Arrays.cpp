#include<iostream>
using namespace std;

int main(){

    int arr[4] = {5, 6, 7, 8};
    int *p = arr;
    int *q = arr+1;
    
    cout << arr << endl; // address of arr
    cout << &arr << endl; // address of arr
    cout << arr[0] << endl; // value of arr
    cout << &arr[0] << endl; // address of arr
    cout << p << endl; // value stored in p
    cout << *p << endl; // value of address stored in p
    cout << &p << endl; // address of p
    cout << q << endl; // value stored in q
    cout << &q << endl; // address of q
    cout << *q << endl; // value of address stored in q

}