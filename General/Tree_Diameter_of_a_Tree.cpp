int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int ans = max(leftHeight, rightHeight) + 1;
    return ans;
}

int diameterOfBinaryTree(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    int op1 = diameterOfBinaryTree(root->left);
    int op2 = diameterOfBinaryTree(root->right);
    int op3 = diameterOfBinaryTree(root->left) + diameterOfBinaryTree(root->right);

    int ans = max(op1, max(op2, op3));
    return ans;
}