#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

// 2 pointer approach

string reverseOnlyLetters(string s){

    int l = 0;
    int h = s.size() - 1;

    while(l<h){
        if(isalpha(s[l]) && isalpha(s[h])){
            swap(s[l], s[h]);
        }
        else if(!isalpha(s[l])){
            l++;
        }
        else{
            h--;
        }
    }
    return s;
}

int main(){
    string s = "Test1ing-Leet=code-Q!";
    cout << reverseOnlyLetters(s) << endl;
}

// TC: O(n)