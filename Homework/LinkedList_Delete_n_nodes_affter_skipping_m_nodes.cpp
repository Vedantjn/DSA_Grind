void linkDelete(struct Node* head, int M, int N){
    if(!head) return 0;
    Node* it = head;

    for(int i = 0; i < M-1; ++i){
        // if M nodea are not available
        if(!it) return;

        it=it->next;
    }

    // it -> would me at Mth node
    if(!it) return;

    Node* MthNode = it;
    it = MthNode->next;

    for(int i = 0; i < N; ++i){
        if(!it) break;

        Node* temp = it->next;
        delete it;
        it = temp;
    }

    MthNode->next = it;
    linkDelete(it, M, N);
}