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
class Solution{
public:
    void fill(TreeNode* root,vector<string>& v,string s){
        if(!root->left&&!root->right){
            s+=(root->val+'a');
            reverse(s.begin(),s.end());
            v.push_back(s);
            return;
        }
        s += (root->val+'a');
        if(root->left)fill(root->left,v,s);
        if(root->right)fill(root->right,v,s);
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> v;
        fill(root,v,"");
        sort(v.begin(),v.end());
        return v[0];
    }
};