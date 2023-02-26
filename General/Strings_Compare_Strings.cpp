#include<iostream>
#include<string.h>
using namespace std;

bool compareStrings(string a, string b){
    if(a.length() != b.length())
        return false;
    else{
        for(int i = 0; i < a.length(); i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
    }
    return true;

}

int main(){
    string s1 = "asdf";
    string s2 = "asdf";
    cout << compareStrings(s1,s2);
}