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
    ListNode* sortList(ListNode* head) {
        return doSort(head);
    }
    ListNode* doSort(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *fast = head, *slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* l2 = slow->next;
        slow->next = NULL;
        ListNode* l1 = head;
        ListNode* leftLL = doSort(l1);
        ListNode* rightLL = doSort(l2);
        
        return merge(leftLL, rightLL);
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        
        ListNode* dummyNode = new ListNode(-1);
        ListNode* head = dummyNode;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                ListNode* newNode = new ListNode(l1->val);
                dummyNode->next = newNode;
                l1 = l1->next;
            }
            else{
                ListNode* newNode = new ListNode(l2->val);
                dummyNode->next = newNode;
                l2 = l2->next;
            }
            dummyNode = dummyNode->next;
        }
        
        if(l1 == NULL){
            dummyNode->next = l2;
        }
        if(l2 == NULL){
            dummyNode->next = l1;
        }
        return head->next;
    }
};