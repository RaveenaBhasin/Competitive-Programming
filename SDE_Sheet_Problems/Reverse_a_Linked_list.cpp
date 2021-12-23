class Solution {
public:
    /*Use three pointers
    curr is a pointer to keep track of current node. Set it to head
    prev is a pointer to keep track of previous node. Set it to NULL
    next_p is a pointer to keep track of next nodes*/
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next_p;
        while(curr!=NULL){
            next_p = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_p;  
        }
        head = prev;
        return prev;
    }
};
//T.C : O(N)  S.C : O(1)