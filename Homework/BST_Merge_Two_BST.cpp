vector<int>merge(Node* root1, Node* root2){
    vector<int>ans; // stores sorted elements of both the trees
    stack<Node*> sa, sb;
    Node* a = root1;
    Node* b = root2;

    while(a || b || !sa.empty() || !sa.empty()){
        while(a){
            sa.push(a);
            a = a->left;
        }
        while(b){
            sa.push(b);
            b = b->left;
        }

        if(sb.empty() || (!sa.empty() && sa.top()->data <= sb.top()->data)){
            auto atop = sa.top();
            ans.push_back(atop->data);
            sa.pop();
            a = atop->right;
        }
        else{
            auto btop = sb.top();
            ans.push_back(btop->data);
            sb.pop();
            b = atop->right;
        }

        }
        return ans;
}
