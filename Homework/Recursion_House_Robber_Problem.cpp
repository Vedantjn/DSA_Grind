#include<iostream>
#include<vector>
using namespace std;

int robHelper(vector<int>& nums, int i){
    // Base case
    if(i >= nums.size()){
        return 0;
    }

    // solution for 1 case
    int robAmount1 = nums[i] + robHelper(nums, i+2); // for robbing
    int robAmount2 = 0 + robHelper(nums, i+1); // for not robbing
    
    return max(robAmount1, robAmount2);
}

int rob(vector<int> &nums){
    return robHelper(nums, 0);
}

int main(){
    vector<int> nums{1, 2, 3, 1};
    cout << rob(nums) << endl;
    return 0;
}

// TC : O(2^n)
// SC : O(n)