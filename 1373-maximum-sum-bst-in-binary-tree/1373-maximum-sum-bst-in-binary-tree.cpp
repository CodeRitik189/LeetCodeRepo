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
    int ans = 0;
    vector<int> check(TreeNode* root){
        if(!root){return {INT_MAX,INT_MIN,0};}
        
        vector<int> lf = check(root->left);
        vector<int> rf = check(root->right);
    
    
        if(root->val>lf[1]&&root->val<rf[0]){
            ans = max(max(ans,lf[2]+rf[2]+root->val),max(lf[2],rf[2]));
            return {min(lf[0],root->val),max(rf[1],root->val),lf[2]+rf[2]+root->val};
        }else{
            return {INT_MIN,INT_MAX,max(lf[2],rf[2])};
        }
    }
    int maxSumBST(TreeNode* root) {
        check(root);
        return ans;
    }
};