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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val=0,carry=0;
        ListNode* head=NULL;
        ListNode* temp=NULL;
        while(l1&&l2){
           val = (l1->val+l2->val+carry)%10;
           carry = (l1->val+l2->val+carry)/10;
           ListNode* t = new ListNode(val);
           if(!head){
               head = t;
               temp = t;
           }
           else{temp->next = t;temp = temp->next;}
           l1 = l1->next;
           l2 = l2->next;
        }
        while(l1){
           val = (l1->val+carry)%10;
           carry = (l1->val+carry)/10;
           ListNode* t = new ListNode(val);
           temp->next = t;
           temp = temp->next;
           l1 = l1->next;
        }
        while(l2){
           val = (l2->val+carry)%10;
           carry = (l2->val+carry)/10;
           ListNode* t = new ListNode(val);
           temp->next = t;
           temp = temp->next;
           l2 = l2->next;
        }
        if(carry!=0){
           ListNode* t = new ListNode(carry);
           temp->next = t;
           temp = temp->next; 
        }
        return head;
    }
};