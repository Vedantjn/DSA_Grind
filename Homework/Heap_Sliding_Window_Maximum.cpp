vector<int>maxSlidingWindow(vector<int>&nums, int k){
    priority_queue<pair<int, int>> pq; // {val, index}
    vector<int>ans;

    // Consider first window
    for(int i = 0; i < k; i++){
        pq.push({nums[i], i});
    }

    // Store max of first window
    ans.push_back(pq.top().first);

    // Consider rest of the windows
    for(int i = k; i < nums.size(); i++){
        pq.push({nums[i], i});

        // Remove is max val is from prev window
        while(pq.top().second <= i-k){
            pq.pop();
        }
        ans.push_back(pq.top().first);
    }
    return ans;
}

// TC : O(NlogN)
// SC : O(N)