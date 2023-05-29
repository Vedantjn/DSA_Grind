class Solution{
public:

    bool isbalanced = true;
    int height(TreeNode* root){
        if(!root) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        // check for current node, is it balanced?
        if(isbalanced && abs(lh - rh) > 1){
            isbalanced = false;
        }

        return max(lh, rh) + 1;
    }

    bool isBalanced(TreeNode* root){
        height(root);
        return isbalanced;
    }
};

// TC : O(n)