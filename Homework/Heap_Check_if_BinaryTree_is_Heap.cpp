// 1). Check Complete Binary Tree or not
// 2). Check whether it follows Max Heap property or not. i.e. Parent > Child

int nodeCount(struct Node* root){
    if(!root) return NULL;
    int l = nodeCount(root->left);
    int r = nodeCount(root->right);
    return 1 + l + r;
}

bool isCBT(struct Node* root, int i, int &n){
    if(!root) return true;
    if(i > n) return false;

    return isCBT(root->left, 2*i, n) && isCBT(root->right, 2*i + 1, n);
}

bool isMaxOrder(struct Node* root){
    if(root == NULL) return true;

    int l = isMaxOrder(root->left);
    int r = isMaxOrder(root->right);

    int ans = false;

    // Leaf node
    if(!root->left && !root->right)
        return true;
    else if(root->left && !root->right){
        ans = root->data > root->left->data;
    }
    else{
        return root->data > root->left->data && root->data > root->right->data;
    }
    return ans && l && r;
}

class Solution{
public:
    bool isHeap(struct Node* tree){
        int n = nodeCount(tree);
        int i = 1;
        return isCBT(tree, i, n) && isMaxOrder(tree);
    }
};