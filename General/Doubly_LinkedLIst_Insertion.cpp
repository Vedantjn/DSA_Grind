#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;

    }
};  

void print(Node* &head){
    Node* temp = head;

    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getLength(Node* head){
    int len = 0;
    Node* temp = head;

    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        // LL is empty
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        // LL is non-empty
        // Step 1: Create a new node
        Node* newNode = new Node(data);
        // Step 2:
        newNode->next = head;
        // Step 3:
        head->prev = newNode;
        // Step 4:
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == 0){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        // Step 1:
        Node* newNode = new Node(data);
        // Step 2:
        tail->next = newNode;
        // Step 3:
        newNode->prev = tail;
        // Step 4:
        tail = newNode;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    if(head == 0){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        if(position == 1){
            insertAtHead(head, tail, data);
            return;
        }

        int len = getLength(head);
        if(position < len){
            insertAtTail(head, tail, data);
            return;
        }
        
        // insertion at position
        // Step 1: Find prev & curr
        int i = 1;
        Node* prevNode = head;
        while(i < position-1){
            prevNode = prevNode->next;
            i++;
        }
        // Node* curr = prevNode;

        // // Step 2:
        Node* newNode = new Node(data);

        // // Step 3:
        // prevNode->next = newNode;
        // newNode->prev = prevNode;
        // curr->prev = newNode;
        // newNode->next = curr;

        prevNode->next->prev = newNode;
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        newNode->prev = prevNode;
    }
}

int main(){
    
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    Node* head = first;
    Node* tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    print(first);
    cout << endl;

    insertAtHead(head, tail, 101);
    print(head);
    cout << endl;

    insertAtTail(head, tail, 102);
    print(head);
    cout << endl;

    insertAtPosition(head, tail, 103, 2);
    print(head);
    cout << endl;

    return 0;
}