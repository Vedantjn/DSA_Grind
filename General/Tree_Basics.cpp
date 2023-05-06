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

int main(){
    Node* root = NULL;
    
    root = buildTree();
    
    return 0;
}