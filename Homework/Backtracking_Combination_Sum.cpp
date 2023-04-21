#include<iostream>
#include<vector>
using namespace std;

void combinationSum_helper(vector<int>&candidates, int target, vector<int>&v, vector<vector<int>> &ans, int index){
    // Base condition
    if(target == 0){
        ans.push_back(v);
        return;
    }
    if(target < 0){
        return;
    }

    for(int i = index; i < candidates.size(); i++){
        v.push_back(candidates[i]);
        combinationSum_helper(candidates, target-candidates[i], v, ans, i);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>&candidates, int target){
    vector<vector<int>> ans;
    vector<int>v;

    combinationSum_helper(candidates, target, v, ans, 0);
    return ans;
}

int main(){
    
    vector<int>candidates{2, 3, 6, 7};
    int target = 7;

    combinationSum(candidates, target);

    return 0;
}