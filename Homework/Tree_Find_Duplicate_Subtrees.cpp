class Solution{
public:

    vector<TreeNode*> ans;
    unordered_map<string, int>subTreeMap;

    string preorder(TreeNode* root){
        if(!root) return "N";

        string curr = to_string(root->val);
        string l = preorder(root->left);
        string r = preorder(root->right);

        string s = curr + "," + l + "," + r;
        if(subTreeMap.find(s) != subTreeMap.end()){
            if(subTreeMap[s] == 1){
                ans.push_back(root);
            }
            subTreeMap[s]++;
        }
        else{
            subTreeMap[s] = 1;
        }
        return s;
    }

    vector<TreeNode> findDuplicateSubtrees(TreeNode* root){
        preorder(root);
        return ans;
    }
};