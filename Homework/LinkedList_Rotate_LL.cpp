int getLength(ListNode* head){
    int len = 0;
    while(head){
        ++len;
        head=head->next;
    }
    return len;
}

ListNode* rotateRight(ListNode* head, int k){
    if(!head) rturn 0;

    int len = getLength(head);
    int actualKRotate = k%len;
    if(actualKRotate == 0) return head;

    int newLastNodePosition = len - actualKRotate - 1;
    ListNode* newLastNode = head;

    for(int i = 0; i < newLastNodePosition; i++){
        newLastNode = newLastNode->next;
    }

    ListNode* newHead = newLastNode->next;
    newLastNode->next = 0;

    ListNode* it = newHead;
    while(it->next){
        it = it->next;
    }
    it->next = head;
    return newHead;
}