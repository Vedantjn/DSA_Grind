class Solution{
public:
    int kthSmallest(TreeNode* root, int &k){

        // base case
        if(root == NULL){
            // -1 reflects base condition reached
            return -1;
        }

        // Inorder LNR

        // left
        int leftAns = kthSmallest(root->left, k);

        if(leftAns != -1){
            return leftAns;
        }

        // root
        k--;
        if(k == 0){
            return root->val;
        }

        // right
        int rightAns = kthSmallest(root->right, k);

        return rightAns;
    }
};