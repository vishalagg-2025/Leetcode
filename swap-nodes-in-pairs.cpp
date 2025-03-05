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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
        return head;

        ListNode *curr = head;
        ListNode *forr = head->next;
        ListNode *prev = NULL;

        while(curr != NULL && curr->next != NULL){
            if(prev == NULL){
                head = forr;
                curr->next = forr->next;
                forr->next = curr;
                prev = curr;
                curr = curr -> next;
                if(curr != NULL)
                forr = curr -> next;
            }else{
                curr->next = forr->next;
                forr->next = curr;
                prev -> next = forr;
                prev = curr;
                curr = curr -> next;
                if(curr != NULL)
                forr = curr -> next;
            }
        }
        return head;
    }
};