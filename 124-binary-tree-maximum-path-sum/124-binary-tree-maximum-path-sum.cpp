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
    int maxi = INT_MIN;
    int maxSum(TreeNode* root){
        if(!root){return 0;}
        int lf = maxSum(root->left);
        int rf = maxSum(root->right);
        maxi = max(maxi,root->val+rf+lf);
        return max(0,root->val+max(rf,lf));
    }
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return maxi;
    }
};