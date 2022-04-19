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
    //as u cannot modify the linkedlist
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next){return NULL;}
        bool fl = false;
        ListNode* t1 = head;
        ListNode* t2 = head->next;
        
        // check whether cycle is present or not
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
        
    // if cycle exists count number of nodes in the cycle
        t1 = t1->next;
        int ct = 1;
        while(t1!=t2){
            ct++;
            t1 = t1->next;
        }
        
        t1 = head;
        t2 = head;
        
       // now start with head and create a window of cycle nodes
        while(ct--){
           t2 = t2 -> next; 
        }
        
    // slide the window until when both the pointers are pointing to the first node of the cycle
        while(t1!=t2){
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }
};