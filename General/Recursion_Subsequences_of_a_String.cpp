#include<iostream>
using namespace std;

void printSubsequences(string str, string output, int i){
    // Base case
    if(i >= str.length()){
        cout << output << endl;
        return;
    }

    // Exclude
    printSubsequences(str, output, i+1);

    // Include
    printSubsequences(str, output + str[i], i+1);
}

int main(){
    string str = "abc";
    string output = "";
    int i = 0;

    printSubsequences(str, output, i);
}