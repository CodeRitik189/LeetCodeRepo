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
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next){return NULL;}
        bool fl = false;
        ListNode* t1 = head;
        ListNode* t2 = head->next;
        
        while(t2&&t2->next){
            if(t2==t1){
              fl = true;
              break;
            }
            t2 = t2->next->next;
            t1 = t1->next;
        }
        if(!fl)
        return NULL; 
        
        t1 = t1->next;
        int ct = 1;
        while(t1!=t2){
            ct++;
            t1 = t1->next;
        }
        
        t1 = head;
        t2 = head;
        
        while(ct--){
           t2 = t2 -> next; 
        }
        while(t1!=t2){
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }
};