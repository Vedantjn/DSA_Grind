#include<iostream>
using namespace std;

class Node{

    public: 
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};  
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5


Node *buildTree(int data)
{
    // -1 data indicates that we have the leaf node (Base Case)
    if (data == -1)
    {
        return NULL;
    }
    // Create the root node and hence solved 1 case
    Node *root = new Node(data);

    // Recursion will handle
    int leftData;
    cout << "Enter the data for left child of " << data << endl;
    cin >> leftData;
    root->left = buildTree(leftData);

    int rightData;
    cout << "Enter the data for right child of " << data << endl;
    cin >> rightData;
    root->right = buildTree(rightData);

    return root;
}

bool KthAncestor(Node* root, int k, int p){
    // Base case
    if(root == NULL){
        return false;
    }

    if(root->data == p){
        return true;
    }
    

    bool leftAns = KthAncestor(root->left, k, p);
    bool rightAns = KthAncestor(root->right, k, p);

    // Waps are honge
    // check left ya right me ans mila ya nhi

    if(leftAns || rightAns){
        k--;
    }
    if(k == 0){
        cout << "Answer: " << root->data;
        k=-1;
    }
    return leftAns || rightAns;

}

int main(){
    
    Node* root = NULL;
    root = buildTree();

    int k = 1;
    int p = 4;
    bool found = KthAncestor(root, k, p);

    return 0;
}