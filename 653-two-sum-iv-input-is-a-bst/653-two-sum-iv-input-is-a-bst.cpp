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
    unordered_map<int,int>um;
    int i=0;
    void preorder(TreeNode* root){
        if(!root){return;}
        um[root->val]= i;
        i++;
        preorder(root->left);
        preorder(root->right);
    }
    
    bool check(TreeNode* root,int k){
        if(!root){return false;}
        if(um.find(k-root->val)!=um.end()&&um[k-root->val]!=um[root->val]){
           return true;
        }
        return check(root->left,k)||check(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        preorder(root);
        return check(root,k);
    }
};