#include<iostream>
using namespace std;

void printPermutations(string &str, int i){
    // base case
    if(i >= str.length()){
        cout << str << " ";
        return;
    }

    // Swapping
    for(int j = i; j < str.length(); j++){
        // swap
        swap(str[i], str[j]);
        // Recursive call
        printPermutations(str, i+1);
        // Backtracking -> To recerate the original input
        swap(str[i], str[j]);
    }
}

int main(){
    string str = "abc";
    int i = 0;
    printPermutations(str, i);
}

// TC: O()