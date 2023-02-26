#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool checkPalindrome(string s, int i, int j){
    while(i <= j){
        if(s[i] != s[j]){
            return false;
        }
        else{
            i++;
            j--;
        }
        return true;
    }
}

// 1 Character remove krne k baad Palindrome

bool validPalindrome(string s){
    int i = 0;
    int j = s.length() - 1;

    while(i <= j)
    {
        if(s[i] != s[j]){
            // ek bar i ko remove ya ekbar j ko remove
            return checkPalindrome(s, i+1, j) || checkPalindrome(s, i, j-1);
        }
        else{
            i++;
            j--;
        }
    }
    return true;
}

int main(){
    string s = "aba";   
    cout << validPalindrome(s);
}