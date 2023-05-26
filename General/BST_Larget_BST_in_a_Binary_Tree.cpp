#include<iostream>
#include<queue>
#include<limits.h>
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


class NodeData{
    public:
    int size;
    int minVal;
    int maxVal;
    bool validBST;

    NodeData(){

    }

    NodeData(int size, int max, int min, bool valid){
        this->size = size;
        minVal = min;
        maxVal = max;
        validBST = valid;
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

NodeData findLargestBST(Node* root, int &ans){
    // base case
    if(root == NULL){
        NodeData temp(0, INT_MIN, INT_MAX, true);
        return temp;
    }

    NodeData leftAns = findLargestBST(root->left, ans);
    NodeData rightAns = findLargestBST(root->right, ans);

    // checking starts here
    NodeData currentNodeAns;

    currentNodeAns.size = leftAns.size + rightAns.size + 1;
    currentNodeAns.maxVal = max(root->data, rightAns.maxVal);
    currentNodeAns.minVal = min(root->data, leftAns.minVal);

    if(leftAns.validBST && rightAns.validBST && (root->data > leftAns.maxVal && root->data < rightAns.minVal)){
        currentNodeAns.validBST = true;
    }
    else{
        currentNodeAns.validBST = false;
    }

    if(currentNodeAns.validBST){
        ans = max(ans, currentNodeAns.size);
    }

    return currentNodeAns;

}

int main(){

    // Node* root = NULL;
    // cout << "Enter the data for this node : "<< endl;
    // takeInput(root);

    Node* root = new Node(5);
    Node* first = new Node(2);
    Node* second = new Node(4);
    Node* third = new Node(1);
    Node* fourth = new Node(3);

    root->left = first;
    root->right = second;
    first->left = third;
    first->right = fourth;

    cout << "Printing the tree :"<< endl;
    levelOrderTraversal(root);

    int ans = 0;
    findLargestBST(root, ans);

    cout << "Largest BST ka size : "<< ans << endl;

    
    return 0;
}

// Inorder of a BST is always sorted