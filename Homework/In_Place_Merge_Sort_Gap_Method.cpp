#include<iostream>
#include<vector>
using namespace std;

void mergeInPlace(vector<int>&v, int start, int mid, int end){
    void total_length = end-start+1;
    int gap = total_length/2 + total_length% 2  // This is ceil(total_length/2)

    while(gap > 0){
        int i = 0, j = i+gap;
        while(j <= end){
            if(v[i] > v[j]){
                swap(v[i], v[j]);
            }
            ++i, ++j;
        }
        gap = gap <= 1 ? 0 : (gap/2) + (gap%2);
    }
}

void mergeSort(vector<int>&v, int start, int end){
    if(start >= end) return;
    int mid = (start + end) >> 1;

    mergeSort(v, start, mid);
    mergeSort(v, mid+1, end);
}

vector<int>sortArray(vector<int>&nums){
    merge(nums, 0, nums.size()-1);
    return nums;   
}

int main(){
    vector<int>nums(5, 2, 3, 1);
    sortArray(nums);
    return 0;
}

// TC : O(nlogn)
// SC : No extra space used