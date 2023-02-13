#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int condition = i <= n/2 ? 2*i : 2*(n-i-1);
        for(int j = 0; j <=condition; j++){
            if(j <= condition/2){
                cout << j+1;
            }
            else{
                cout << condition - j + 1; 
            }
        }
        cout << endl;

    }
}