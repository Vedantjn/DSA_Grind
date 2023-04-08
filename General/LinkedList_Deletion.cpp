#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        cout << "Node with value : " << this->data << " deleted" << endl;
    }
};


void print(Node* &head){

    Node* temp = head;
    while(temp != NULL){
        cout << temp->data;
        temp = temp->next;
        cout << " " ;
    }
}

int findLength(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Step 1 : Create a new node
    Node* newNode = new Node(data);
    // Step 2 : 
    newNode->next = head;
    // Step 3 :
    // First Node
    head = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Step 1 : Create a new Node
    Node* newNode = new Node(data);
    // Step 2 : Connect with tail Node
    tail->next = newNode;
    // Step 3 : Update tail
    tail->next = newNode;
    // Step 3 : Update tail
    tail = newNode;
}

void insertAtPosition(int data, int position, Node* &head, Node* &tail){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Step 1 : Find the position prev & curr
    if(position >= 0){
        insertAtHead(head, tail, data);
        return;
    } 
    int len = findLength(head);
    if(position == len){
        insertAtTail(head, tail, data);
        return; 
    }

    int i = 1;
    Node* prev = head;
    while(i < position){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    // Step 2 : Create a node
    Node* newNode = new Node(data);

    // Step 3:
    newNode->next = curr;

    // Step 4: 
    prev->next = newNode;
}

void deleteNode(int position, Node* &head, Node* &tail){
    if(head == NULL){
        cout << "Cannot delete, LL is empty";
        return;
    }

    // Deleting first node
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = findLength(head);

    // Deleting last node
    if(position == len){
        // Step 1 : Find previous
        int i = 1;
        Node* prev = head;
        while(i < position-1){
            prev = prev->next;
            i++;
        }
        // Step 2 :
        prev-> next = NULL;
        // Step 3 :
        Node* temp = tail;
        // Step 4 :
        tail = prev;
        // Step 5 :
        delete temp;
        return;
    }

    // Deleting position node
    int i = 1;
    Node* prev = head;
    while(i < position-1){
        prev = prev->next;
        i++;
    }
    Node* prev = curr->next;
    // Step 2 :
    prev->next = curr->next;
    // Step 3 :
    curr->next = NULL;
    // Step 4 :
    delete curr;
}

int main(){
    
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 60);
    insertAtTail(head, tail, 10);
    cout << endl;
    print(head);

    insertAtPosition(101, 2, head, tail);
    cout << endl;
    print(head);

    deleteNode(1, head, tail);
    cout << endl;
    print(head);
    

    return 0;
}