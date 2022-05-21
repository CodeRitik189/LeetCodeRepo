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
//     unordered_map<int,int>um;
//     int i=0;
//     void preorder(TreeNode* root){
//         if(!root){return;}
//         um[root->val]= i;
//         i++;
//         preorder(root->left);
//         preorder(root->right);
//     }
    
//     bool check(TreeNode* root,int k){
//         if(!root){return false;}
//         if(um.find(k-root->val)!=um.end()&&um[k-root->val]!=um[root->val]){
//            return true;
//         }
//         return check(root->left,k)||check(root->right,k);
//     }
    stack<TreeNode*>prev;
    stack<TreeNode*>nxt;
    
    void create(TreeNode* root){
        pushleft(root);
        pushright(root);
    }
    
    void pushleft(TreeNode* root){
        if(!root){return ;}
        nxt.push(root);
        pushleft(root->left);
    }
    void pushright(TreeNode* root){
        if(!root){return ;}
        prev.push(root);
        pushright(root->right);
    }
    
    TreeNode* next(){
        TreeNode* nx = nxt.top();
        nxt.pop();
        pushleft(nx->right);
        return nx;
    }
    
    TreeNode* previous(){
        TreeNode* pr = prev.top();
        prev.pop();
        pushright(pr->left);
        return pr;
    }
    
    bool findTarget(TreeNode* root, int k) {
        //preorder(root);
        //return check(root,k);
        create(root);
        
        TreeNode* i = next();
        TreeNode* j = previous();
        
        while(i->val<j->val){
            if(i->val+j->val == k){
                return true;
            }else if(i->val+j->val<k){
                i = next();
            }else{
                j = previous();
            }
        }
        return false;
    }
};