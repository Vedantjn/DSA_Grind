#include<iostream>
#include<algorithm>
using namespace std;

// Counting Method

bool validAnagram(string s, string t){

    int frequencyTable[256] = {0};

    for(int i = 0; i < s.size(); i++){
        frequencyTable[s[i]]++;
    } // O(n)

    for(int i = 0; i < t.size(); i++){
        frequencyTable[t[i]]--;
    } // O(m)

    for(int i = 0; i < 256; i++){
        if(frequencyTable[i] != 0){
            return false;
        }
    } // O(256)
    return true;
}

int main(){
    string s = "anagram";
    string t = "nagaram";
    cout << validAnagram(s, t);
}

// TC: O(n + m + 256) = O(n + m)