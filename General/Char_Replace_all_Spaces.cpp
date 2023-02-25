#include<iostream>
#include<string.h>
using namespace std;

void replaceSpaces(char sentence[]){

    int i = 0;
    int n = strlen(sentence);

    for(int i = 0; i < n; i++){
        if(sentence[i] == " "){
            sentence[i] == '@';
        }
    }
}

int main(){
    char sentence[100];
    cin.getline(sentence, 100);
    
    cout << sentence << endl;
    replaceSpaces(sentence);
    cout << sentence << endl;
}