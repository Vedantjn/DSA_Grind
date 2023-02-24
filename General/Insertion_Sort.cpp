#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int>arr{10,1,7,6,14,9};
    int n = arr.size();

    for(int round = 1; round < n; round++){
        // Step A: Fetch
        int val = arr[round];
        int j = round-1;
        // Step B: Compare
        for(; j>0; j--){
            if(arr[j] > val){
                // Step C: Shift
                arr[j+1] = arr[j];
            }
            else{
                // Rukna hai
                break;
            }
        }
        // Step D: Copy
        arr[j+1] = val;
    }

    // Printing
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
}


// TC: O(n^2) in normal case, O(n) in best case, O(n^2) in worst case
// SC: O(1)