#include<iostream>
#include<limits.h>
using namespace std;

int checkKey(string& str, int& n, char& key, int i){
    // Base case
    if(i >= n){
        // Key not found
        return -1;
    }

    // 1 case solve kro
    if(str[i] == key){
        return i;
    }

    // baki recursion sambhalega
    return checkKey(str, n, key, i+1);
}

int main(){
    string str = "vedantjain";
    int n = str.length();
    int i = 0;

    char key = 'j';

    int ans = checkKey(str, n, key, i);
    cout << ans << endl;
}
