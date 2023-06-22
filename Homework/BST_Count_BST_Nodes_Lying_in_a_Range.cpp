int rangeInBST(TreeNode* root, int low, int high){
    if(!root) return 0;
    int ans = 0;

    bool wasInRange = false;

    if(root->val >= low && root->val <= high){
        wasInRange = true;
        ans += root->val;
    }

    if(wasInRange){
        ans += rangeInBST(root->left, low, high) + rangeInBST(root->right, low, high);
    }
    else if(root->val < low){
        ans += rangeInBST(root->right, low, high);
    }
    else{
        ans += rangeInBST(root->left, low, high);
    }
    return ans;
}