#include<iostream>
using namespace std;

// ? -> single character
// * -> any number of characters

bool isMatchHelper(string& s, int si, string& p, int pi){
    // Base case
    if(si == s.size() && pi == p.size()){
        return true;
    }

    if(si == s.size() && pi < p.size()){
        while(pi < p.size()){
            if(p[pi] != '*') return false;
            pi++;
        }
        return true;
    }

    // Single character matching
    if(s[si] == p[pi] || '?' == p[pi]){
        return isMatchHelper(s, si+1, p, pi+1);
    }

    if(p[pi] == '*'){
        // Treat * as empty or null
        bool caseA = isMatchHelper(s, si, p, pi+1);

        // Let * consume one character
        bool caseB = isMatchHelper(s, si+1, p, pi);

        return caseA || caseB;
    }
    // Character does'nt match
    return false;
}

bool isMatch(string s, string p){
    int si = 0; // Pointer index for s string 
    int pi = 0; // Pointer index for p string 

    return isMatchHelper(s, si, p, pi);
}

int main(){
    string s = "abcdefg";
    string p = "ab*fg";
    cout << isMatch(s, p) << endl;
    return 0;
}

// TC : O(2^n) // fibonacci
// SC : O(n)