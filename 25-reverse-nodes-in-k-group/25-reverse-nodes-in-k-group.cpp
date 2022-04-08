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
    ListNode* reverse(ListNode* head){
        if(!head||!head->next){
            return head;
        }
        ListNode* temp = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp; 
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head){
            return NULL;
        }
        ListNode* temp = head;
        int num = k;
        while(temp&&num>1){
            temp = temp -> next;
            num--;
        }
        if(temp){
          temp->next = reverseKGroup(temp->next,k); 
          ListNode* t1 = temp -> next;
          temp -> next = NULL;
          temp = reverse(head);
          head->next = t1;
          return temp;
        }else{
           return head;
        }
    }
};