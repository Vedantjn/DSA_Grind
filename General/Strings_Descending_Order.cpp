#include<iostream>
#include<algorithm>

using namespace std;

bool comp(char first, char second){
    return first>second;
}

int main(){

    string s = "vedant";
    sort(s.begin(), s.end(), comp);
    cout << s << endl;
}