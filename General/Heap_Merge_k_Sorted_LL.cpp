class compare{
public:
    bool operator(ListNode* a, ListNode* b){
        return a->val > b-> val;
    }

};

class Solution{
public:

    ListNode* mergeKLists(vector<ListNode*> &lists){
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        int k = lists.size();
        if(k == 0){
            return NULL;
        }

        // First element of every LL ko insert kro heap me
        for(int i = 0; i < k; i++){
            if(lists[i] != NULL){
                minHeap.insert(lists[i]);
            }
        }

        ListNode* head = NULL:
        ListNode* tail = NULL;

        while(!minHeap.empty()){
            ListNode* temp = minHeap.top();
            minHeap.pop();

            // temp may or may not be first element of answer LL 
            if(head == NULL){
                // temp -> first element of answer LL
                head = temp;
                tail = temp;
                if(tail -> next != NULL){
                    minHeap.push(tail->next);
                }
            }
            else{
                // temp is not the first element of LL
                tail->next = temp;
                tail = temp;
                if(tail->next != NULL){
                    minHeap.push(tail->next);
                }
            }
        }
        return head;

    }
};