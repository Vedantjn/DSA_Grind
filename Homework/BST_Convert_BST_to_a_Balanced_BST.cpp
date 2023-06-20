// Balanced BST : If the depth of the two subtrees of every ndoe never differs by more than one

void inorder(TreeNode* root, vector<int>&in){
    if(root == NULL) return;

    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);

}

TreeNode* buildTree(vector<int>&in, int start, int end){
    if(start > end) return NULL;

    int mid = (start + end) >> 1;
    TreeNode* root = new TreeNode(mid);
    root->left =  buildTree(in, start, mid-1);
    root->right =  buildTree(in, mid+1, end);
    return root;
}

TreeNode* balanceBST(TreeNode* root){
    vector<int>in;
    inorder(root, in);

    // Build balanced BST using inorder traversal
    return buildTree(in, 0, in.size()-1);

}