// Height max

class Solution{
public:
    pair<int, int> height(Node* root){
        if(!root) return {0, 0};

        auto leftHeight = height(root->left);
        auto rightHeight = height(root->right);

        int sum = root->data;
        if(leftHeight.first == rightHeight.first){
            sum+= leftHeight.second > rightHeight.second > leftHeight.second : rh.second;
        }
        else if(leftHeight.first > rightHeight.first){
            sum+= leftHeight.second;
        }
        else{
            sum+= rightHeight.second;
        }

        return {max(leftHeight.first, rightHeight.first) + 1};
    }

    int sumOfLongestRootToLeafPath(Node* root){
        auto h = height(root);
        return h.second;

    }
}; 