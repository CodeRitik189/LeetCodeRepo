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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }else if(l2==NULL){
            return l1;
        }
        ListNode* temp1= l1;
        ListNode* temp2 = l2;
         ListNode* head=NULL;
         ListNode* tail=NULL;
        while(temp1!=NULL&&temp2!=NULL){
          //  cout<<temp1->val<<" "<<temp2->val<<" ";
            if(temp1->val < temp2->val){
                if(head==NULL){
                    head=temp1;
                    temp1=temp1->next;
                    tail=head;
                }else{
                tail->next=temp1;
                temp1=temp1->next;
                tail=tail->next;
                tail->next=NULL;
                }
            }else{
                if(head==NULL){
                    head=temp2;
                    temp2=temp2->next;
                    tail=head;
                }else{
                tail->next=temp2;
                temp2=temp2->next;
                tail=tail->next;
                tail->next=NULL;
                }
            }
        }
        if(temp1==NULL){
            while(temp2!=NULL){
                tail->next=temp2;
                temp2=temp2->next;             
                tail=tail->next; 
                tail->next=NULL;
            }
        }else if(temp2==NULL){
            while(temp1!=NULL){
                tail->next=temp1;
                temp1=temp1->next;
                tail=tail->next;
                tail->next=NULL;
            }
        }
        return head;
    }
};