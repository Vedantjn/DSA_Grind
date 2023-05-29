class Solution{
public:
    int D = 0;
    int height(TreeNode* root){
        if(!root) return 0;

        int lh = height(root->left);
        int rh = height(root->right);
        // diameter
        int currD = lh + rh;
        D = max(D, currD);
        return max(lh, rh) + 1;
    }

    int diameterOfBT(TreeNode* root){
        height(root);
        return D;
    }
};

// TC : O(n)