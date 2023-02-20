#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>&nums){
    // Visited approach
    int ans = -1;

    for(int i = 0; i < nums.size(); i++){
        int index = abs(nums[i]);

        // Already visited
        if(nums[index] < 0){
            ans = index;
            break;
        }

        // Visited mark
        nums[index]*= -1;
    }
    return ans;
}

int main(){
    vector<int>nums{1,3,4,2,2};
    cout << findDuplicate(nums) << endl;
}

// TC: O(n)
// SC: O(1)