#include <iostream>
#include <queue>
#include <map>
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


void levelOrderTraversal(Node *root)
{
    // Empty tree
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    // Push the root in queue
    q.push(root);
    q.push(NULL);
    // Run the loop until queue becomes empty
    while (!q.empty())
    {
        // Fetch front node and then pop
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // go to the next line
            cout << endl;
            // Marking for next level
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            // left child exists
            if (temp->left)
            {
                q.push(temp->left);
            }
            // right child exists
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void printTopView(Node* root) {
        if(root == NULL )
                return;
        
        ///create a map for storing HD -> TopNode ->data
        map<int, int> topNode;

        //Level Order
        //we will store a pair consisting of Node and Horizontal Distance
        queue< pair<Node*, int> > q;
        q.push(make_pair(root, 0));

        while(!q.empty()) {
                pair<Node*, int> temp = q.front();
                q.pop();

                Node* frontNode = temp.first;
                int hd = temp.second;

                //jo bhi horizontal distance aaya h , check if answer for that hd already exists
                //or not
			
                if(topNode.find(hd) == topNode.end()) {
                        //crete entry
                        topNode[hd] = frontNode->data;
                }

                if(frontNode -> left)
                        q.push(make_pair(frontNode->left, hd-1));

                if(frontNode -> right)
                        q.push(make_pair(frontNode->right, hd+1));
        }

        //ab aapka answer store hua hoga aapke map me 
        cout << "Printing the answer: " << endl;
        for(auto i: topNode) {
                cout << i.first << " -> " << i.second << endl;
        }
}

int main()
{
    Node* root = buildTree();
    printTopView(root);
}