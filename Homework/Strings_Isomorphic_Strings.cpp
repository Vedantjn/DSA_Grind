#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isIsomorphic(string s, string t){
    int hash[256] = {0}; // mapping from mapping of each character of language s -> language t
    bool isTCharsMapped[256] = {0}; // stores if t[i] char already mapped with s[i]

    for(int i = 0; i < s.size(); i++){
        if(hash[s[i]] == 0 && isTCharsMapped[t[i]] == 0){
            hash[s[i]] = t[i];
            isTCharsMapped[t[i]] = true;
        }
    }

    for(int i = 0; i < s.size(); i++){
        if(char(hash[s[i]]) != t[i]){
            return false;
        }else{
            return true;
        }
    }
}

int main(){
    string s = "egg";
    string t = "add";
    cout << isIsomorphic(s, t) << endl;
}