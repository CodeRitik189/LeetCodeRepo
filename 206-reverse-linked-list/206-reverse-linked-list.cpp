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
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next){return head;}
        // if(!head||!head->next){
        //     return head;
        // }
        // ListNode* temp = reverseList(head->next);
        // head->next->next = head;
        // head->next = NULL;
        // return temp;
        ListNode* t1=head;
        ListNode* t2=head->next;
        t1 -> next = NULL;
        while(t2){
           ListNode* temp = t2->next;
           t2->next = t1;
           
           t1 = t2;
           t2 = temp;
        }
        return t1;
    }
};