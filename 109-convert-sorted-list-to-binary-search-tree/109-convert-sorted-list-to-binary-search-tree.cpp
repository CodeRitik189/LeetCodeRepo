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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* construct(ListNode* head){
        if(!head){
            return NULL;
        }
        if(!head -> next){
            TreeNode* node = new TreeNode(head->val);
            return node;
        }
        ListNode* temp1 = head;
        int ct = 0,mid;
        while(temp1){
           temp1 = temp1->next;
           ct++;
        }
        mid = (ct)/2-1;
        temp1 = head;
        while(mid--){
            temp1 = temp1->next;
        }
        ListNode* temp = temp1->next->next;
        temp1 -> next->next = NULL;
        TreeNode* node = new TreeNode(temp1->next->val);
        temp1 -> next = NULL;
        
        node -> left = construct(head);
        node -> right = construct(temp);
        
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
       return  construct(head);
    }
};