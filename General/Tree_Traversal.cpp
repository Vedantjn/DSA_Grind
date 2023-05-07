
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

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

void inorderTraversal(Node* root){
    // Base case
    if(root == NULL){
        return;
    }

    // L N R
    inorderTraversal(root->left);
    cout << root->data;
    inorderTraversal(root->right);

}

preorderTraversal(Node* root){
    // Base case
    if(root == NULL){
        return;
    }

    // N L R
    cout << root->data;
    preorderTraversal(root->left);
    preorderTraversal(root->right);

}

postorderTraversal(Node* root){
    // Base case
    if(root == NULL){
        return;
    }

    // L R N
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data;

}

int main()
{
    Node *root;
    int data;
    cout << "Enter data for root node" << endl;
    cin >> data;
    root = buildTree(data);
    preOrderTraversal(root);
    return 0;
}