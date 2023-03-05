#include<iostream>
using namespace std;

void solve(int **ptr){
    **ptr = **ptr+1;  // Pass by value -> Copy created  
}

int main(){
    int a = 5;
    int *p = &a;
    int **q = &p;

    solve(q);

    cout << a << endl;

}