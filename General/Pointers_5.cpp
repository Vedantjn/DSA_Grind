#include<iostream>
using namespace std;

void solve(int* &ptr){
    ptr = ptr+1;  // Pass by reference
}

int main(){
    int a = 5;
    int *p = &a;

    cout << p << endl;
    solve(p);
    cout << p << endl;

}