// Lowest Common Ancestor
class SOlution{
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){

        // base case
        if(root == NULL){
            return NULL;
        }

        if(p->val < root-> val && q->val < root->val){
            // p and q left subtree me exist krte hain
            return lowestCommonAncestor(root->left, p, q);
        }

        if(p->val > root-> val && q->val > root->val){
            // p and q right subtree me exist krte hain
            return lowestCommonAncestor(root->right, p, q);
        }

        // koi ek node chhoti hai aur dusri badi hai
        
        // if(p->val < root->val && q->val > root->val){
        //     return root;
        // }
        // if(p->val > root->val && q->val < root->val){
        //     return root;
        // }

        return root;
    }
};