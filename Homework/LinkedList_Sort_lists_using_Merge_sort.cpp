ListNode* findMid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* merge(ListNode* list1, ListNode* list2){
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

ListNode* sortList(ListNode* head){
    if(head == 0 || head->next == 0){
        return head;
    }

    // Break it into two halves using mid node
    ListNode* mid = findMid(head);
    ListNode* left = left;
    ListNode* right = mid->next;
    mid->next = 0;

    // Sort recursively
    left = sortList(left);
    right = sortList(right);

    // Merge both left and right ll
    ListNode* mergedll = merge(left, right);
    return mergedll;

}

// TC : O(nlogn)