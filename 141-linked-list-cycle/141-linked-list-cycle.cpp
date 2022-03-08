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
        if(head==NULL){
            return false;
        }
        ListNode* t1 = head;
        ListNode* t2 = head->next;
        if(t2==NULL||t2->next==NULL){
            return false;
        }
        while( t2!=NULL && t2->next != NULL){
            if(t1==t2){
                return true;
            }
            t1=t1->next;
            t2=t2->next->next;
        }
        return false;
    }
};