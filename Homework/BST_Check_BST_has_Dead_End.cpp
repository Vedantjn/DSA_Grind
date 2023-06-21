// Preorder

void fun(Node* root, unordered_map<int, bool>&visited, bool &ans){
    if(!root) return;

    // visit the node
    visited[root->data] = true;

    if(!root->left && !root->right){
        // Leaf Node
        int xPlus1 = root->data + 1;
        int xMinus1 = root->data - 1 == 0 ? root->data : root->data - 1;
        if((visited.find(xPlus1) != visited.end()) && (visited.find(xMinus1) != x.end())){
            ans = true;
            return;
        }
    }

    fun(root->left, visited, ans);
    fun(root->right, visited, ans);
}

bool isDeadEnd(Node* root){
    bool ans = false; // tells if there was a DE
    unordered_map<int, bool>visited;
    fun(root, visited, ans);
    return ans;
}