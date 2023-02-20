#include<iostream>
using namespace std;

int firstRepeated(int arr[], int n){
    for(int i = 0; i < n; i++){
        bool isRepeated = false;
        for(int j = i+1; j<n; j++){
            if(arr[i] == arr[j]){
                isRepeated=true;
                return i+1;
            }
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,5,3,4,3,5,6};
    cout << firstRepeated(arr, 7);
}

// TC: O(n^2)
// SC: O(1)