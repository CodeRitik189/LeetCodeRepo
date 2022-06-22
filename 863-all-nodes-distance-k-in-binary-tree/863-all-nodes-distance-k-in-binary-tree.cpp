/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     vector<int>ans;
 
    void find(TreeNode* root,int k){
        if(!root || k<0 ){ return; }
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        
        find(root->left,k-1);
        find(root->right,k-1);
    }
    
    int check(TreeNode* root, int tg , int k){
        if(!root){ return 1e5; }
        if(root->val == tg){
            find(root,k);
            return 1;
        }
        int a1 = check(root->left,tg,k);
        int a2 = check(root->right,tg,k);
        
        if(a1 == 1e5 && a2 == 1e5){
            return 1e5;
        }else if(a2==1e5){
            k !=a1 ? find(root->right,k-a1-1) :ans.push_back(root->val);
        }else{
            k !=a2 ? find(root->left,k-a2-1) :ans.push_back(root->val);
        }
        return 1+min(a1,a2);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        ans = vector<int>(0);
        check(root,target->val,k);
        return ans;
    }
};