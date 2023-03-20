#include<iostream>
using namespace std;

void reverse(string &s, int start, int end){
    // Base case
    if(start >= end){
        return;
    }

    // ek case
    swap(s[start], s[end]);

    // Recursive call
    reverse(s, start+1, end-1);
}

int main(){
    string s = "abcd";

    int start = 0;
    int end = s.size() - 1;
    reverse(s, start, end);
    cout << s << endl;
}

// TC: O(n)
// SC: O(n)