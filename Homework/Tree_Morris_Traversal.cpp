class Solution{
public:
    vector<int>inorderTraversal(TreeNode* root){
        vector<int>ans;
        TreeNode* curr = root;
        while(curr){
            // Left node is nullptr, then visit it and go right
            if(curr->left = nullptr){
                ans.push_back(curr->val);
                curr = curr->right;
            }
                // Left node is not nullptr
            else
            {
                // Find inorder predecessor
                TreeNode* prev = curr->left;
                while(pred->right){
                    pred = pred->right;
                }

                // If pred right node is nullptr, then go left after establishing link from predecessor to current
                if(pred->right == nullptr){
                    pred->right = curr;
                    curr = curr->left;
                }
                else{
                    // Right node is not null
                    // left is already visited, go right after visiting current node while removing the link
                    pred->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }   
        }
        return ans;
    }
};