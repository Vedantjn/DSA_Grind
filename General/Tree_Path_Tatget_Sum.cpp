void solve(TreeNode* root, int targetSum, int currSum, vector<int>path, vector<vector<int>>&ans){
    // Base case
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        if(currSum == target){
            ans.push_back(path);
        }
        return;
    }

    // Include current node
    path.push_back(root->val);
    currSum+=root->val;

    solve(root->left, targetSum, currSum, path, ans);
    solve(root->right, targetSum, currSum, path, ans);
}

vector<vector<int>>pathSum(TreeNode* root, int targetSum){
    vector<vector<int>>ans;
    int sum = 0;
    vector<int>temp;
    solve(root, targetSum, sum, temp, ans);
    return ans;
}