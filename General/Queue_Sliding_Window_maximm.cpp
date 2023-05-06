#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int>maxSlidingWindow(vector<int>&nums, int k){
    deque<int>dq;
    vector<int>ans;

    // first window
    for(int i = 0; i < k; i++){
        // chote element remove krdo
        while(!dq.empty() && nums[i] >= nums[dq.back()]){
            dq.pop_back();
        }
        // Inserting index so that we can check out of window element
        dq.push_back(i);
    }

    // Store answer for first window
    ans.push_back(nums[dq.front()]);

    // Remaining windows ko process krna hai
    for(int i = k; i < nums.size(); i++){
        // out of window element ko remove kr dia
        if(!dq.empty() && i - dq.front() >= k){
            dq.pop_front();
        }

        // ab firse current element k lie chote element ko remove krna hai
        while(!dq.empty() && nums[i] >= nums[dq.back()]){
            dq.pop_back();
        }
        // Inserting index so that we can check out of window element
        dq.push_back(i);

        // current window ka answer store krna h
        ans.push_back(nums[dq.front()]);

    }
}

int main(){
    vector<int>nums{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    cout << maxSlidingWindow(nums, k) << endl;
    return 0;
}