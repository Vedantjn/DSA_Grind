void inorder(Node* root, Node* &prev){
    if(!root)
        return;

    inorder(root->left, prev);
    
    prev->left = 0;
    prev->right = root;
    prev = root;
    
    inorder(root->right, prev);
}

Node* flatten(Node* root){
    Node* dummy = new Node(-1);
    Node* prev = dummy;

    inorder(root, prev);
    
    prev->left = prev->right = 0;
    root = dummy->right;

    return root;
}

// TC : O(N)
// SC : O(H)