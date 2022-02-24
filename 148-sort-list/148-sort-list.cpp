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
    ListNode* merged(ListNode* fs,ListNode* ls){
        if(!fs){return ls;}
        if(!ls){return fs;}
        ListNode* t1 = fs;
        ListNode* t2 = ls;
        ListNode* head=NULL;
        ListNode* temp=NULL;
        while(t1&&t2){
            if(t1->val<t2->val){
                ListNode* t = t1->next;
                t1->next = NULL; 
                if(!head){
                 head = t1;
                 temp = t1;
                }else{
                 temp->next = t1;
                 temp = temp->next;
                }
                t1 = t;
            }else{
                ListNode* t = t2->next;
                t2->next = NULL; 
                if(!head){
                 head = t2;
                 temp = t2;
                }else{
                 temp->next = t2;
                 temp = temp->next;
                }
                t2 = t;
            }
        }
        if(t1){
            if(!head){return t1;}
            temp->next = t1;
        }
        if(t2){
            if(!head){return t2;}
            temp->next = t2;
        }
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next){return head;}
        ListNode* t1 = head;
        ListNode* t2 = head->next;
        while(t2&&t2->next){
            t2 = t2->next->next;
            t1 = t1->next;
        }
        t2 = t1->next;
        t1->next = NULL;
        ListNode* fs = sortList(head);
        ListNode* ls = sortList(t2);
       return merged(fs,ls);
    }
};