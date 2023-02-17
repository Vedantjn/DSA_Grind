#include<iostream>
#include<vector>
using namespace std;

int findPeakIndex(vector<int>arr){
    int s = 0;
    int e = arr.size()-1;
    int mid = s+(e-s)/2;

    while(s<e){
        if(arr[mid] < arr[mid+1]){
            // Right search
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int peakIndexInAMountainArray(vector<int>&nums){
    return findPeakIndex(nums);
}

int main(){

    vector<int> nums{1,22,3, 21, 33, 42};
    
    cout << peakIndexInAMountainArray(nums) << endl;
}