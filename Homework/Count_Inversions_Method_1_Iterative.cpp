#include<iostream>
#include<vector>
using namespace std;

int countInversions(vector<int> arr){
    int count = 0;
    for(int i = 0; i < arr.size(); i++){
        for(int j = i+1; j < arr.size(); j++){
            count = arr[i] > arr[j] ? count++ : count;
        }
    }
    return count;
}

int main(){
    vector<int>arr{8, 4, 2, 1};

    cout << countInversions(arr) << endl;
    return 0;
}

// TC: O(n^2)