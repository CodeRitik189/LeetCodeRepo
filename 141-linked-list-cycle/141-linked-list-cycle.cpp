/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head||!head->next){return false;}
        
        ListNode* t1 = head;
        ListNode* t2 = head->next;
        
        while(t2&&t2->next){
            if(t2==t1){
                return true;
            }
            t2 = t2->next->next;
            t1 = t1->next;
        }
        return false;
    }
};