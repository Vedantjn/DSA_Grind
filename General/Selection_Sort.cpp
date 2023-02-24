#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int>arr{5,4,3,2,1};
    int n = arr.size();

    // Outer loop-> No. of rounds
    // Inner loop-> Index of minimum element in range i to n

    for(int i = 0; i < n-1; i++){

        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                // new minimum
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }

    // Printing
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
}

// TC: O(n^2)
// SC: O(1)