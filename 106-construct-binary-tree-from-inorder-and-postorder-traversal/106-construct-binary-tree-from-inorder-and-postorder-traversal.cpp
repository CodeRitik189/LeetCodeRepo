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
    TreeNode* create(vector<int>& post, vector<int>& in,int ps,int pe,int is,int ie){
        if(ps>pe){return NULL;}
        TreeNode* root = new TreeNode(post[pe]);
        root->left = create(post,in,ps,ps+um[post[pe]]-is-1,is,um[post[pe]]-1);
        root->right = create(post,in,pe-(ie-um[post[pe]]),pe-1,um[post[pe]]+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
         for(int i=0;i<in.size();i++){
            um[in[i]] = i;
        }
        return create(post,in,0,post.size()-1,0,in.size()-1);
    }
};