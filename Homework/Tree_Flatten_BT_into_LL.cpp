class Solution{
public:
    void flatten(TreeNode* root){
        TreeNode* curr = root;
        while(curr){
            if(curr -> left){
                TreeNode* predecessor = curr->left;
                while(pred->right)
                    pred = pred->right;
                
                pred->right = curr->right;
                cutt->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};