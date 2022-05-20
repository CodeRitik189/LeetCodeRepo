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
     vector<long>left;
    vector<long>right;
    void check(TreeNode* root,long dist,int level){
           if(!root){return;}
            if(level>=left.size()){
                left.push_back(dist);
                right.push_back(dist);
            }
            left[level] = dist<left[level]?dist:left[level];
            right[level] = dist>right[level]?dist:right[level];
        long i = dist-left[level];
        check(root->left,2*i+1,level+1);
        check(root->right,2*i+2,level+1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        left.push_back(0);
        right.push_back(0);
        check(root->left,1,1);
        check(root->right,2,1);
        int ans = 1;
        for(int i = 0 ; i<left.size();i++){
            ans = ans>right[i]-left[i]+1?ans:right[i]-left[i]+1;
        }
        return ans;
    }
};