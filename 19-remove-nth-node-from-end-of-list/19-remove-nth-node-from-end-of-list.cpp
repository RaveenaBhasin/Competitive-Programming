/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *next_p = NULL;
        while(curr!=NULL){
            next_p = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_p;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = reverseLinkedList(head);
        head = dummyNode;
        ListNode* curr = head, *prev = NULL;
        for(int i = 0; i < n; i++){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        return reverseLinkedList(head->next);
    }
};