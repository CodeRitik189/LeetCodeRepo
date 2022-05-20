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
    TreeNode* head=NULL;
    void flat(TreeNode* root){
        if(!root){return;}
        if(!head){
            head = root;
        }else{
            head->right = root;
            head = head->right;
        }
        TreeNode* temp = root->right;
        flat(root->left);
        root->left = NULL;
        flat(temp);
    }
    void flatten(TreeNode* root) {
        flat(root);
        return;
    }
};