#include<iostream>
using namespace std;

void solve(int &num){
    num = 50;
}

int main(){
    int a = 5;

    solve(a);

    cout << a << endl;

}