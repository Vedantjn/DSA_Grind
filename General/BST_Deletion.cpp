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
Node* findNodeinBST(Node* root, int target){
    // base case
    if(root == NULL){
        return NULL;
    }

    if(root->data == target){
        return root;
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

int maxVal(Node* root){
    Node* temp = root;

    if(temp == NULL){
        return -1;
    }

    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}


Node* deleteNodeInBST(Node* root, int target) {
	
	//base cae
	if(root == NULL ) {
		return NULL;
	}
//cout << "Request recieved for " >> root->data << " with target" << target << endl;
	if(root->data == target) {
		//isi ko delete krna h 
		//4 cases 
		if(root->left == NULL && root->right == NULL) {
			//leaf node
			//delete root;
			return NULL;
		}
		else if(root->left == NULL && root->right != NULL) {
			Node* child = root->right;
			//delete root;
			return child;
		}
		else if(root->left != NULL && root->right == NULL) {
			Node* child  = root->left;
			//delete root;
			return child;
		}
		else {
			//both child
			//find inorder predecessor inb left subtree
			int inorderPre = maxVal(root->left);
			//replace root->data value with inorder predecessor
			root->data = inorderPre;
			//delete inorder predecessor from left subtree
			root->left = deleteNodeInBST(root->left,inorderPre);
			return root;
			
		}
		
	}
	else if(target > root -> data) {
		//right jana chahiye
		root->right =  deleteNodeInBST(root->right, target);
	}
	else if(target < root->data) {
		//left jana chahioye
		root->left = deleteNodeInBST(root->left, target);
	}
	return root;
}

int main(){

    Node* root = NULL;
    cout << "Enter the data for Node "<< endl;
    takeInput(root);

    cout << "Printing the tree "<< endl;
    levelOrderTraversal(root);
    
    deleteNode(root, 150);
    levelOrderTraversal(root);
    return 0;
}

// Inorder of a BST is always sorted