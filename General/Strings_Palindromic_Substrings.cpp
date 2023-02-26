#include<iostream>
#include<string>
#include<vector>
using namespace std;

    int expandAroundIndex(string s, int left, int right) {
        int count = 0;
        //jab tak match karega, tab tak count increment kardo and i piche and j aaage kardo
        while(left >= 0 && right <s.length() && s[left] == s[right] ) {
            count++;
            left--;
            right++;
        }
        return count;
    }


int countSubstrings(string s){
    int count = 0;
    int n = s.length();

    for(int i = 0; i < n; i++){
        // Odd
        int oddKaAns = expandAroundIndex(s, i, i);
        count = count + oddKaAns;
        // Even
        int evenKaAns = expandAroundIndex(s, i, i+1);
        count = count + evenKaAns;
    }
    return count;
}

int main(){
    string s = "aaa";
    cout << countSubstrings(s);
}