class Solution {
public:
    static bool cmp(vector<int>& p1, vector<int>& p2){
        return p1[1] > p2[1];
    }
    void insert(unordered_map<int,int>& um,vector<vector<int>>& v){
        for(auto x:um){
            v.push_back({x.first,x.second});
        }
    }
    int minimumOperations(vector<int>& nums) {
        if(nums.size()==1){return 0;}
        int ec = 0, oc = 0;
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        
        for(int i = 0; i<nums.size(); i++){
            if(i%2==0){
                ec++;
                m1[nums[i]]++ ;
            }else{
               oc++;
               m2[nums[i]]++;
            }
        }
        vector<vector<int>>v1;
        vector<vector<int>>v2;
        
        insert(m1,v1);
        insert(m2,v2);
        
        sort(v1.begin(),v1.end(),cmp);
        sort(v2.begin(),v2.end(),cmp);
        
        if(v1[0][0]==v2[0][0]){
     return nums.size()-max((v1[0][1]+(v2.size()>1?v2[1][1]:0))
                            ,(v2[0][1]+(v1.size()>1?v1[1][1]:0)));
        }else{
            return nums.size() - (v1[0][1]+v2[0][1]); 
        }
    }
};