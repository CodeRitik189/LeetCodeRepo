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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size(), n = nums.size();
        for(int i=0;i<q;i++){
            queries[i].push_back(i);
            swap(queries[i][0],queries[i][1]);
        }
        
        vector<int>ans(q);
        sort(nums.begin(),nums.end());
        sort(queries.begin(),queries.end());
        
        Trie tr;
        
        int i = 0,j = 0;
        
        while(i<n && j<q){
          while(i<n && nums[i]<=queries[j][0]){
            tr.insert(nums[i]); 
            i++;
          }
          ans[queries[j][2]] = i>0 ? tr.cal(queries[j][1]) : -1;
          j++;
        }
        while(j<q){
          ans[queries[j][2]] = tr.cal(queries[j][1]);
          j++;  
        }
        return ans;
    }
};