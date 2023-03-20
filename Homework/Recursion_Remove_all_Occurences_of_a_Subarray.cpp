#include<iostream>
#include<algorithm>
using namespace std;

void removeOccurenceRecursively(string& s, string& part){

    int found = s.find(part);
    if(found != string::npos){
        // part string has been located
        // Please remove it
        string left_part = s.substr(0, found);
        string right_part = s.substr(found + part.size(), s.size());
        s = left_part+ right_part;

        removeOccurenceRecursively(s, part);
    }
    else{
        // base case
        // all the occurences of part has been removed from s
        return;
    }
}

string removeOccurences(string s, string part){
    removeOccurenceRecursively(s, part);
    return s;
}

int main(){
    string s = "daabcbaabcbc";
    string part = "abc";

    cout << removeOccurences(s, part) << endl;
}

// n -> s.size() ; m -> part.size()
//  TC: O(n^2)
//  SC: O(n*m)