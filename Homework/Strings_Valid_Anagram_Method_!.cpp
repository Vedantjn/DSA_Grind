#include<iostream>
#include<algorithm>
using namespace std;

// Bruteforce method -> Sorting

bool validAnagram(string s, string t){

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if(s == t){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s = "anagram";
    string t = "nagaram";
    cout << validAnagram(s, t);
}

// TC: O(n*log(n))