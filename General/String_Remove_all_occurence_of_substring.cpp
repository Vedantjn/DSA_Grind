#include<iostream>
#include<string>
#include<vector>
using namespace std;

string removeOccurence(string s, string part){

    int pos = s.find(part);

    while(pos != string::npos){
        s.erase(pos, part.length());
        pos = s.find(part);
    }
    return s;
}

int main(){
    string s = "daaabcabbbbb";
    string part = "abc";

    cout << removeOccurence(s, part);
}