#include<iostream>
using namespace std;

// Right to left approach

void lastOccurenceRightToLeft(string& s, char c, int i, int &ans){
    // base case
    if(i < 0){
        return;
    }

    // ek case solve
    if(s[i] == c){
        ans = i;
        return;
    }

    // recursive call
    lastOccurenceRightToLeft(s, c, i-1, ans);
}

int main(){
    string s = "abcddefg";
    char x = 'd';

    int ans = -1;
    int i = s.size() - 1;
    lastOccurenceRightToLeft(s, x, i, ans);

    cout << ans << endl;
}

// Method 1: Search from left to right
// Method 2: Search from right to left
// Method 3: STL function: strrchr()

// TC: O(n)
// SC: O(n)