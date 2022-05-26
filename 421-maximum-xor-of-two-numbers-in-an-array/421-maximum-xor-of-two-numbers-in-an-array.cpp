struct Node{
    Node* child[2];    
    Node(){
       for(int i=0;i<2;i++){
           child[i] = NULL;
       }
    }
};

class Trie{

    public:

    Node* root;
    Trie() {
       root = new Node();
    }

    void insert(int num){
        // Write your code here.
        Node* node = root;
        for(int i=31;i>=0;i--){
            int bit = ((num>>i)&1);
            if(!node->child[bit])
              node->child[bit] = new Node();
            node = node->child[bit];
        }
    }
    int cal(int num){
        Node* node = root;
        int xr = 0;
        for(int i=31;i>=0;i--){
            int bit = ((num>>i)&1);
            
            if(!node->child[1-bit]){
               node = node->child[bit];
                xr *= 2;
            }else{
               node = node->child[1-bit];
                xr = ((xr*2)|1);
            }
        }
        return xr;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie tr;
        int ans = 0;
        for(int i = 0 ; i<nums.size(); i++){
            tr.insert(nums[i]);
        }
        for(int i = 0 ; i<nums.size(); i++){
            ans = max(ans,tr.cal(nums[i]));
        }
        return ans;
    }
};