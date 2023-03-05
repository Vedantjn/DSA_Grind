#include<iostream>
using namespace std;

void util(int *p){
    *p = *p+1;    // Pass by value -> Copy created
}

int main(){
    int a = 5;
    int *p = &a;

    cout << "Before" << endl;
    cout << a << endl;
    cout << p << endl;
    cout << *p << endl;

    util(p);

    cout << "After" << endl;
    cout << a << endl;
    cout << p << endl;
    cout << *p << endl;

}