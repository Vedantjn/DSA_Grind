#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s){

    if(s.size() == 0){
        return true;
    }

    int fnd = s.find("abc");

    if(fnd != string::npos){
        // Found
        string tleft = s.substr(0, fnd);
        string tright = s.substr(fnd+3, s.size());
        return isValid(tleft + tright);
    }

}

int main(){

    string s = "aabcbc";
    cout << isValid(s) << endl;
    
    return 0;
}

// TC : O(n^2)