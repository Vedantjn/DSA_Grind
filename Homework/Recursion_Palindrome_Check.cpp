#include<iostream>
using namespace std;

bool isPalindrome(string& s, int start, int end){
    // Base case
    if(start >= end){
        return true;
    }

    // ek case solve
    if(s[start] != s[end]){
        return false;
    }

    return isPalindrome(s, start+1, end-1);
}

int main(){
    string s = "racecar";
    int start = 0;
    int end = s.size() - 1;
    cout << isPalindrome(s, start, end) << endl;
}

// TC: O(n)
// SC: O(n)