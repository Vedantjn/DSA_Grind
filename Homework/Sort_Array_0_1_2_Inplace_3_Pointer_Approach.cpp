#include<iostream>
#include<vector>
using namespace std;

void sortElements(vector<int>nums){
    int low = 0;
    int mid = 0;
    int high = nums.size()-1;

    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main(){
    vector<int> v{1, 2, 0, 2, 1};
    sortElements(v);
}

// TC: O(n)
// SC: O(1)