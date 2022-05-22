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
    // both l1 and l2 cover the same m+n distane=ce until reaching the intersection point
    // thats wahy they reach at that at the same time
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // if(!headA->next)return headA;
        // if(!headB->next)return headB;

        ListNode* l1 = headA;
        ListNode* l2 = headB;
        
        while(l1!=l2){
            if(!l1){
                l1 = headB;
            }else{
                l1 = l1->next;
            }
            if(!l2){
                l2 = headA;
            }else{
                l2 = l2->next;
            }
        }
       return l1;
    }
};