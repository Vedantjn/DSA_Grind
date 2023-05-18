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
            this->left = left;
            this->right = right;
        }
};


void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	//initially
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		//A
		Node* temp = q.front();
		//B
		q.pop();
		
		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}	
		}
		else {
			//C
			cout << temp->data << " ";
			//D
			if(temp -> left) {
				q.push(temp ->left);
			}
			if(temp ->right) {
				q.push(temp->right);
			}
		}
		
		
	}
}


Node* insertIntoBST(Node* root, int data){

    if(root == NULL){
        // This is the first node we have to create
        root = new Node(data);
        return root;
    }

        // Not the first node
        if(root->data > data){
            // Insert in left
            root->left = insertIntoBST(root->left, data);
        }
        else{
            // Insert in right
            root->right = insertIntoBST(root->right, data);
        }
        return root;
}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// Assuming there are only unique values in tree
bool findNodeinBST(Node* root, int target){
    // base case
    if(root == NULL){
        return false;
    }

    if(root->data == target){
        return true;
    }

    if(target > root->data){
        // Search in right subtree
        return findNodeinBST(root->right, target);
    }
    else{
        // Search in left subtree
        return findNodeinBST(root->left, target);
    }
}

int minVal(Node* root){
    Node* temp = root;

    if(temp == NULL){
        return -1;
    }

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}

Node* bstUsingInorder(int inorder[], int s, int e){
    // base case
    if(s > e){
        // Invalid array
        return NULL;
    }

    int mid = s + (e-s)/2;
    int element = inorder[mid];

    Node* root = new Node(element);

    root->left = bstUsingInorder(inorder, s, mid-1);
    root->right = bstUsingInorder(inorder, mid+1, e);

    return root;
}

int main(){

    int inorder[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int s = 0;
    int e = 8;

    Node* root = bstUsingInorder(inorder, s, e);

    levelOrderTraversal(root);

    return 0;
}

// Inorder of a BST is always sorted