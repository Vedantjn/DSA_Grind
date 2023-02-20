#include<iostream>
#include<algorithm>
using namespace std;

int firstRepeated(int arr[], int n){
    // Hashing
    unordered_map<int, int>hash;
    for(int i = 0; i < n; i++){
        hash[arr[i]]++;
    }

    for(int i = 0; i < n; i++){
        if(hash[arr[i]>1]){
            // repeated
            return i+1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,5,3,4,3,5,6};
    cout << firstRepeated(arr, 7);
}

// TC: O(n)
// SC: O(n)