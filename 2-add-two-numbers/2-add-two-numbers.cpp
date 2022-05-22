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
        ListNode* head=NULL;
        ListNode* temp = head;
        int carry=0,vl=0;
        while(l1&&l2){
            vl = (carry+l1->val+l2->val)%10;
            carry = (carry+l1->val+l2->val)/10;
            ListNode* nxt = new ListNode(vl);
            if(!head){
              head = nxt;  
              temp = nxt;
            }else{
               temp->next =  nxt;
               temp = temp->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            vl = (carry+l1->val)%10;
            carry = (carry+l1->val)/10;
            ListNode* nxt = new ListNode(vl);
            if(!head){
              head = nxt;  
              temp = nxt;
            }else{
               temp->next =  nxt;
               temp = temp->next;
            } 
            l1 = l1->next;
        }
        while(l2){
            vl = (carry+l2->val)%10;
            carry = (carry+l2->val)/10;
            ListNode* nxt = new ListNode(vl);
            if(!head){
              head = nxt;  
              temp = nxt;
            }else{
               temp->next =  nxt;
               temp = temp->next;
            }
            l2 = l2->next;
        }
        if(carry>0){
           ListNode* nxt = new ListNode(carry);
           temp->next =  nxt;
        }
        return head;
    }
};