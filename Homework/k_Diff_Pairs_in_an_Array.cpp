#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int findPairs(vector<int>&nums, int k){
    sort(nums.begin(), nums.end());
    set<pair<int, int>>ans;
    int i = 0;
    int j = 1;

    while(j < nums.size()){
        int diff = nums[j] - nums[i];
        if(diff == k){
            ans.insert({nums[i], nums[j]});
            ++i;
            ++j;
        }
        else if(diff > k){
            i++;
        }
        else{
            j++;
        }
        if(i == j){
            j++;
        }
    }
    return ans.size();
}

int main(){

    vector<int>nums{3,1,4,1,5};
    int k = 2;

    cout << findPairs(nums, k);

}