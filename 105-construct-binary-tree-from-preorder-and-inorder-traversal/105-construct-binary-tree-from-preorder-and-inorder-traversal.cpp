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
    unordered_map<int,int>um;
    TreeNode* create(vector<int>& pre, vector<int>& in,int ps,int pe,int is,int ie){
        if(ps>pe){return NULL;}
        TreeNode* root = new TreeNode(pre[ps]);
        root->left = create(pre,in,ps+1,ps+um[pre[ps]]-is,is,um[pre[ps]]-1);
        root->right = create(pre,in,ps+um[pre[ps]]-is+1,pe,um[pre[ps]]+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for(int i=0;i<in.size();i++){
            um[in[i]] = i;
        }
        return create(pre,in,0,pre.size()-1,0,in.size()-1);
    }
};