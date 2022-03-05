class Solution {
public:
    int find(vector<vector<int>>& v,int ind,vector<int>&dp){
        if(ind>=v.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int ans=v[ind][0]*v[ind][1];
          if(ind<v.size()-1){
            if(v[ind+1][0]==v[ind][0]+1){
             ans += find(v,ind+2,dp);
             ans = max(ans,find(v,ind+1,dp));
            }else{
                ans += find(v,ind+1,dp);
            }
        }
        dp[ind]=ans;
        return ans;
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        int id=nums[0],ct=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=id){
                v.push_back({id,ct});
                id=nums[i];
                ct=1;
            }else{
                ct++;
            }
        }
         v.push_back({id,ct});
         vector<int>dp(v.size(),-1);
        return find(v,0,dp);
    }
};