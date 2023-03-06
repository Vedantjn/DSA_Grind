#include<iostream>
using namespace std;

bool isPalindrome(string& s, int start, int end){
    while(start < end){
        if(s[start] != s[end]){
            return false;
        }
        start++, end--;
    }
    return true;
}

string longestPalindrome(string s){
    string ans = "";

    for(int i = 0; i < s.size(); i++){
        for(int j = i; j < s.size(); j++){
            if(isPalindrome(s, i, j)){
                string t = s.substr(i, j-i+1);
                ans = t.size() > ans.size() ? t : ans;
            }
        }
    }
        return ans;
}

int main(){
    string s = "babad";
    cout << longestPalindrome(s) << endl;
}

// TC: O(n*n*n)
// SC: O(1)
