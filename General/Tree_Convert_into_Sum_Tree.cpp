void convertIntoSumTree(TreeNode* root){
    // Base case
    if(root == NULL)
        return 0;

    int leftAns = convertIntoSumTree(root->left);
    int rightAns = convertIntoSumTree(root->right);

    root->data = leftAns + root->data + rightAns;
    return root->data;
}