/**
 * Definition for singly-linked list.
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        else{
            ListNode* curr = head;
            while(curr!=NULL && curr->next!=NULL){
                int temp = curr->val;
                curr->val = curr->next->val;
                curr->next->val = temp;
                curr = curr->next->next;
            }
        }
        return head;
    }
};