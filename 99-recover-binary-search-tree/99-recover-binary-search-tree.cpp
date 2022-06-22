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
    TreeNode* prev = new TreeNode(INT_MIN);
    TreeNode* p1=NULL;
    TreeNode* p2=NULL;
    
    void check(TreeNode* root){
        if(!root){ return; }
        check(root->left);
        
        if(prev->val > root->val){
           if(!p1)
             p1 = prev;
           p2 = root;
        }
        prev = root;
        check(root->right);
    }
    void recoverTree(TreeNode* root) {
         check(root);
         swap(p1->val,p2->val);
         return ;
    }
};