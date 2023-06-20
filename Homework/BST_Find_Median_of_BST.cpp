struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// Using Morris Traversal

int findNodeCount(Node* root){
    int count = 0;
    Node* curr = root;
    while(curr){
        // Left node is nullptr, then visit it and go right
        if(curr->left = nullptr){
            count++;
            curr = curr->right;
        }
            // Left node is not nullptr
        else
        {
            // Find inorder predecessor
            Node* prev = curr->left;
            while(pred->right){
                pred = pred->right;
            }
            // If pred right node is nullptr, then go left after establishing link from predecessor to current
            if(pred->right == nullptr){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                // Right node is not null
                // left is already visited, go right after visiting current node while removing the link
                pred->right = nullptr;
                count++;
                curr = curr->right;
            }
        }   
    }
    return count;
}

float findActualMedian(Node* root, int n){
    int i = 0;
    int odd1 = (n+1)/2, odd1Val = -1;
    int even1 = (n/2), even1Val = -1;
    int even2 = (n/2 + 1), even2Val = -1;

    Node* curr = root;
    while(curr){
        // Left node is nullptr, then visit it and go right
        if(curr->left = nullptr){
            i++;
            if(i == odd1) odd1Val = curr->data;
            if(i == even1) even1Val = curr->data;
            if(i == even2) even2Val = curr->data;
            curr = curr->right;
        }
            // Left node is not nullptr
        else
        {
            // Find inorder predecessor
            Node* prev = curr->left;
            while(pred->right){
                pred = pred->right;
            }
            // If pred right node is nullptr, then go left after establishing link from predecessor to current
            if(pred->right == nullptr){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                // Right node is not null
                // left is already visited, go right after visiting current node while removing the link
                pred->right = nullptr;
                i++;
                if(i == odd1) odd1Val = curr->data;
                if(i == even1) even1Val = curr->data;
                if(i == even2) even2Val = curr->data;
                curr = curr->right;
            }
        }   
    }
    float median = 0;
    if((n%1) == 0){
        // even
        median = (even1Val + even2Val) / 2.0;
    }
    else{
        // odd
        median = odd1Val;
    }
    return median;
}

float findMedian(struct Node* root){
    int n = findNodeCount(root);
    return findActualMedian(root, n);
}

// TC : O(N)
// SC : O(1)