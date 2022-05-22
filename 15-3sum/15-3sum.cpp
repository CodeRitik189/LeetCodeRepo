class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       int n = nums.size();
       if(n<3){return {};}
        
     //  set<vector<int>>sv;
       sort(nums.begin(),nums.end());
       vector<vector<int>>ans;
       for(int i=0;i<nums.size()-2;i++){
           if(i>0&&nums[i-1]==nums[i]){
               continue;
           }
           int j=i+1,k=n-1;
           while(j<k){
             int sum = nums[i]+nums[j]+nums[k];
             if(sum==0){
                 ans.push_back({nums[i],nums[j],nums[k]});
                int b = nums[j],c = nums[k];
                while(j<n&&nums[j]==b)
                 j++;
                while(k>=0&&nums[k]==c)
                 k--;
             }else if(sum<0){
                 j++;
             }else{
                 k--;
             }
           }
       }
        // for(auto v:sv){
        //     ans.push_back(v);
        // }
        return ans;
    }
};