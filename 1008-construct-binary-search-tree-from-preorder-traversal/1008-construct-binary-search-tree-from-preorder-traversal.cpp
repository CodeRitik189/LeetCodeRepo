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
    // sorting the preorder for finding inorder can be an approach but there is a case where 
    // approach can be made in o(N) time complexity
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(preorder,i,INT_MAX);
    }
    TreeNode* solve(vector<int>& pre,int& i,int up){
        if(i==pre.size()||pre[i]>up){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[i++]);
        root->left = solve(pre,i,root->val);
        root->right = solve(pre,i,up);
        
        return root;
    }
};