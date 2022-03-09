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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next){
           return head;
        }
        while(head!=NULL&&head->next!=NULL){
          if(head->next->val==head->val){
                int num = head->val;
                  while(head!=NULL&&head->val==num){
                     head = head->next;
                  }
             }else{
                 break;
             }
          }
         if(!head){
             return head;
           }
           ListNode* temp1 = head;
           ListNode* temp2 = head->next;
         while(temp2!=NULL&&temp2->next!=NULL){
            if(temp2->next->val==temp2->val){
                int num = temp2->val;
                  while(temp2!=NULL&&temp2->val==num){
                     temp2 = temp2->next;
                  }
             }else{
                temp1->next=temp2;
                temp1 = temp1->next;
                temp2 = temp2->next;
             }
        }
        temp1->next=temp2;
        return head;
    }
};