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
    vector<int>ans;
    void postorder(TreeNode* root){
        if(!root){ return; }
        
        postorder(root->left);
        postorder(root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        //postorder(root);
        if(!root){
            return {};
        }
        stack<TreeNode*> st;
        stack<TreeNode*> st2;
        st.push(root);
        while(!st.empty()){
            TreeNode* t = st.top();
            st2.push(t);
            st.pop();
            
            if(t->left)
            st.push(t->left);
            
            if(t->right)
            st.push(t->right);
        }
        
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};