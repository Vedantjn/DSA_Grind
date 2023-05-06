#include<iostream>
#include<queue>
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

Node* buildTree(){

    int data;
    cout << "Enter the data "<< endl;
    cin >> data;
    
    if(data == -1){
        return NULL;
    }

    // Step 1
    Node* root = new Node(data);

    // Baki recursion

    // Step 2
    cout << "Enter data for left child of " << data << endl;
    root->left = buildTree();

    // Step 3
    cout << "Enter data for right child of " << data << endl;
    root->left = buildTree();

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

int main(){
    Node* root = NULL;

    root = buildTree();

    levelOrderTraversal(root);
    
    return 0;
}