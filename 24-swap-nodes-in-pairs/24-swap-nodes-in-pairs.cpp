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
        if(!head||!head->next){
            return head;
        }
        head -> next -> next = swapPairs(head->next->next);
        ListNode* nxt = head->next;
        head -> next = nxt->next;
        nxt -> next = head;
        return nxt;
    }
};