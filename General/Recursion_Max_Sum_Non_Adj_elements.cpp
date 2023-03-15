#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// We have to return the maximum sum of subsequence in which no two elements are adjacent
void solve(vector<int>&arr, int i, int sum, int& maxi){
    // Base case
    if(i >= arr.size()){
        // maxi update
        maxi = max(sum, maxi);
        return ;
    }

    // Include
    solve(arr, i+2, sum+arr[i], maxi);

    // Exclude
    solve(arr, i+1, sum, maxi);
}

int main(){

    vector<int> arr{2, 1, 4, 9};
    int sum = 0;
    int maxi = INT_MIN;
    int i = 0;

    solve(arr, i, sum, maxi);

    cout << maxi << endl;
}