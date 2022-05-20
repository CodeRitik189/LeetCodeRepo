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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root){
       return {};
    }
   int mn=0,mx=0;
   queue<pair<TreeNode*,int>> q;
   unordered_map<int,unordered_map<int,vector<int>>>um;
   q.push({root,0});
   int k = 1,lvl = 0;
        
        while(!q.empty()){
            int k = q.size();
        while(k--){
                pair<TreeNode*,int> temp = q.front();
                q.pop();
                mn = min(mn,temp.second);
                mx = max(mx,temp.second);
                um[temp.second][lvl].push_back(temp.first->val);
                if(temp.first->left){q.push({temp.first->left,temp.second-1});}
                if(temp.first->right){q.push({temp.first->right,temp.second+1});}
           }
            lvl++;
        }
        vector<vector<int>>ans;
        for(int i=mn;i<=mx;i++){
            vector<int>v;
            for(int j=0;j<lvl;j++){
                vector<int>t = um[i][j];
                sort(t.begin(),t.end());
                for(int k=0;k<t.size();k++){
                    v.push_back(t[k]);
                }
            }
           ans.push_back(v);
        }
        return ans;
    }
};