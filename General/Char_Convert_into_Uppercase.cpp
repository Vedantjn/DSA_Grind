#include<iostream>
#include<string.h>
using namespace std;

void convertIntoUppercase(char arr[]){
    int n = strlen(arr);

    for(int i = 0; i < n; i ++){
        arr[i] = arr[i] - 'a' + 'A';
    }
}

int main(){
    char arr[100] = "vedant";
    convertIntoUppercase(arr);
    cout << arr << endl;
}