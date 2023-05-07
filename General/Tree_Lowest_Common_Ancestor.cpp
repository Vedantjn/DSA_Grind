TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    // Base case
    if(root == NULL)
        return NULL;

    // Check for p and q
    if(root->val == p-> val){
        return p;
    } 
    if(root->val == q->val){
        return q;
    }

    Node* leftAns = lowestCommonAncestor(root->left, p, q);
    Node* rightAns = lowestCommonAncestor(root->right, p, q);

    if(leftAns == NULL && rightAns == NULL){
        return NULL;
    }
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else{
        return root;
    }
}