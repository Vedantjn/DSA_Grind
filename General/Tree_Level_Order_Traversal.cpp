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

void levelOrderTraversal(Node* root){

    queue<Node*>q;

    // Initially push root
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        // Step 1
        Node* temp = q.front();

        // Step 2
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }        
        else{
            // Step 3
            cout << temp->data << endl;

            // Step 4
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}

int main(){
    Node* root = NULL;

    root = buildTree();

    levelOrderTraversal(root);
    
    return 0;
}