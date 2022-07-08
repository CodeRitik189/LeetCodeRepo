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
    unordered_map<long long int,int>um;
    void check(TreeNode* root,long long int sum, int& tg){
        if(!root)return;
        
        if(um.find(sum+root->val-tg)!=um.end()){
            ans += um[sum+root->val-tg];
        }
        um[sum+root->val]++;
        check(root->left,sum+root->val,tg);
        check(root->right,sum+root->val,tg);
        
        um[root->val+sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        um[0] = 1;
        check(root,0,targetSum);
        return ans;
    }
};