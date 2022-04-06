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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // could have replaced one list to a complete sorted 
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* head=NULL;
        ListNode* temp=NULL;
        while(list1&&list2){
           if(list1->val<list2->val){
               if(!head){
                   head = new ListNode(list1->val);
                   temp = head;
               }else{
                   temp->next = new ListNode(list1->val);
                   temp = temp->next;
               }
               list1 = list1->next;
           }else{
               if(!head){
                   head = new ListNode(list2->val);
                   temp = head;
               }else{
                   temp->next = new ListNode(list2->val);
                   temp = temp->next;
               }
               list2 = list2->next;
           } 
        }
        while(list1){
            if(!head){
                head = new ListNode(list1->val);
                temp = head;
            }else{
                temp->next = new ListNode(list1->val);
                temp = temp->next;
            }
             list1 = list1->next; 
        }
         while(list2){
            if(!head){
                head = new ListNode(list2->val);
                temp = head;
            }else{
                temp->next = new ListNode(list2->val);
                temp = temp->next;
            }
             list2 = list2->next; 
        }
        return head;
    }
};