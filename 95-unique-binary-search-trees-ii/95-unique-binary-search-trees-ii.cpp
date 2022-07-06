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
    void update(TreeNode* root, int& vl){
        if(!root)return;
        update(root->left,vl);
        vl++;
        root->val = vl;
        update(root->right,vl);
    }
    vector<TreeNode*> find(int n){
        vector<TreeNode*>v;
        for(int i = 0; i< n; i++){
            vector<TreeNode*>left = find(i);
            vector<TreeNode*>right = find(n-1-i);
            
            for(int x = 0; x<left.size(); x++){
                for(int y = 0; y<right.size(); y++){
                    TreeNode* root = new TreeNode(0);
                    root->left = left[x];
                    root->right = right[y];
                    v.push_back(root);
                }
            }
        }
       if(v.size()==0)v.push_back(NULL);
       return v;
    }
    vector<TreeNode*> generateTrees(int n) {
       vector<TreeNode*> v = find(n);
        
       for(int i = 0; i<v.size(); i++){
           int vl = 0;
           update(v[i],vl);
       }
        return v;
    }
};