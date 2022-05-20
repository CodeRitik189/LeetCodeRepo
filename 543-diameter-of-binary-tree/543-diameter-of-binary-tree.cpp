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
    int dia = 1;
    int check(TreeNode* root){
        if(!root){return 0;}
        int lh = check(root->left);
        int rh = check(root->right);
        dia = max(dia,lh+rh+1);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        check(root);
        return dia-1;
    }
};