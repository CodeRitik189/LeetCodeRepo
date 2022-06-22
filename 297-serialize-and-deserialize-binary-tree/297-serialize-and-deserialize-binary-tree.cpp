/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        serialhelp(root,ans);
        cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int j = 0;
       return deserialhelp(data,j);
    }
    
    
    void serialhelp(TreeNode* root,  string& ans){
        if(!root){
            return ;
        }
        ans += to_string(root->val);
        ans += 'L';
        serialhelp(root->left,ans);
        ans += 'L';
        serialhelp(root->right,ans);
    }
    
    TreeNode* deserialhelp(string& data, int& j){
        if(j >= data.size() || data[j] == 'L'){j++; return NULL;}
        int num = 0,sign = 1;
        if(data[j] == '-'){
            sign = -1;
            j++;
        }
        while(j<data.size() && data[j] != 'L'){
            num = num*10 + (data[j]-'0');
            j++;
        }
        j++;
        TreeNode* root = new TreeNode(sign*num);
        root->left = deserialhelp(data,j);
        root->right = deserialhelp(data,j);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));