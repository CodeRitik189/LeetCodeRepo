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
    long prev = LONG_MIN;
    bool check(TreeNode* root){
        if(!root){
            return true;
        }
        bool ans = true;
        ans &= check(root->left);
        ans &= (root->val>prev);
        prev = root->val;
        ans &= check(root->right);
        
        return ans;
    }
    bool isValidBST(TreeNode* root) {
        return check(root);
    }
};