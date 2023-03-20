#include<iostream>
using namespace std;

// Left to right approach

void lastOccurenceLeftToRight(string& s, char c, int i, int &ans){
    // Base case
    if(i >= s.size()){
        return;
    }

    // ek case solve
    if(s[i] == c){
        ans = i;
    }

    // recursive call
    lastOccurenceLeftToRight(s, c, i+1, ans);
}

int main(){
    string s = "abcddefg";
    char x = 'd';

    int ans = -1;
    int i = 0;
    lastOccurenceLeftToRight(s, x, i, ans);

    cout << ans << endl;
}

// Method 1: Search from left to right
// Method 2: Search from right to left
// Method 3: STL function: strrchr()

// TC: O(n)
// SC: O(n)