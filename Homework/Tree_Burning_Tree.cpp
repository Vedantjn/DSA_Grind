struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

class Solution{

    public:

        Node* makeNodeToParentMappingAndFindTargetNode(Node* root, unordered_map<Node*, Node*>&parentMap, int target){
            queue<Node*>q;
            Node* targetNode = 0;
            q.push(root);
            parentMap[root] = 0;

            while(!q.empty()){
                Node* front = q.front();
                q.pop();

                if(front->data == target){
                    targetNode = front;
                }

                if(front->left){
                    q.push(front->left);
                    parentMap[front->left] = front;
                }

                if(front->right){
                    q.push(front->right);
                    parentMap[front->right] = front;
                }
            }
            return targetNode;
        }

        int burnTheTree(Node* targetNode, unordered_map<Node*, Node*>parentMap){
            unordered_map<Node*, bool> isBurnt;
            queue<Node*>q; // currently set on fire nodes
            int T = 0;
            q.push(targetNode);
            isBurnt[targetNode] = 1;

            while(!q.empty()){
                int size = q.size();
                bool isFireSpreaded = 0;
                for(int i = 0; i < size; i++){
                    Node* front = q.front();
                    q.pop();

                    if(front->left && !isBurnt[front->left]){
                        q.push(front->left);
                        isBurnt[front->left] = 1;
                        isFireSpreaded = 1;
                    }

                    if(front->right && !isBurnt[front->right]){
                        q.push(front->right);
                        isBurnt[front->right] = 1;
                        isFireSpreaded = 1;
                    }

                    if(parentMap[front] && !isBurnt[parentMap[front]]){
                        q.push(parentMap[front]);
                        isBurnt[parentMap[front]] = 1;
                        isFireSpreaded = 1;
                    }
                }
                if(isFireSpreaded)
                    ++T;
            }
            return T;
        }

        int minTime(Node* root, int target){
            unordered_map<Node*, Node*>parentMap; // Node -> its parent pointers
            Node* targetNode = makeNodeToParentMappingAndFindTargetNode(root, parentMap, target);
            return burnTheTree(targetNode, parentMap);
        }
};