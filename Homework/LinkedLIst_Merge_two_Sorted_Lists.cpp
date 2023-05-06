ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    if(left == 0) return right;
    if(right == 0) return left;

    ListNode* ans = new ListNode(-1);
    ListNode* mptr = ans;

    hile(left && right){
        if(left->val <= right->val){
            mptr->next = left;
            mptr = left;
            left=left->next;
        }
        else{
            mptr->next = right;
            mptr = right;
            right = right->next;
        }
    }

    if(left){
            mptr->next = left;
            // mptr = left;
            // left=left->next;
    }

    if(right){
            mptr->next = right;
            // mptr = right;
            // right = right->next;
    }

    return ans->next;

}