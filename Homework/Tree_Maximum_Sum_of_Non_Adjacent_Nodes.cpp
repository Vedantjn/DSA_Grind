class Solution{
public:
    pair<int, int>getMaxSumHelper(Node* root){
        if(root == NULL){
            return {0, 0};
        }

        auto left = getMaxSumHelper(root->left);
        auto right = getMaxSumHelper(root->right);

        // Sum including the node
        int a = root->data + left.second + right.second;

        // Sum excluding the node
        int b = max(left.first, left.second) + max(right.first, right.second);

        return {a, b};
    }

    int getMaxSum(Node* root){

        auto ans = getMaxSumHelper(root);
        return max(ans.first, ans.second);
    }
};