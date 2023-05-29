class Solution{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> ans;
        if(!root) return ans;
        bool leftToRight = true;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int width = q.size();
            vector<int>oneLevel(width);
            for(int i = 0; i < width; i++){
                TreeNode* front = q.front();
                q.pop();
                int index = leftToRight ? i : width - i -1;
                oneLevel[index] = front->val;
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            // Toggle the direction
            leftToRight = !leftToRight;
            ans.push_back(oneLevel);
        }
        return ans;
    }
};

// TC = SC = O(n)