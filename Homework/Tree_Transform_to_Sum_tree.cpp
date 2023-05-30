class Solution{
public:

    int sum(TreeNode* root){

        if(!root) return 0;

        if(!root->left && !root->right){
            // leaf node
            int temp = root->data;
            root->data = 0;
            return temp;
        }

        int leftSum = sum(root->left);
        int rightSum = sum(root->right);
        int temp = root->data;
        root->data = leftSum + rightSum;
        return root->data + temp;
    }


    void toSumTree(Node *node){
        sum(node);
    }
};