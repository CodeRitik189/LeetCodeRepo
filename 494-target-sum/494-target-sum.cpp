class Solution {
public:
    vector<unordered_map<int,int>>dp;
    int check(vector<int>& nums,int n, int tg){
         if(n==0){return tg==0;}
         if(dp[n].find(tg)!=dp[n].end()){return dp[n][tg];}
         return dp[n][tg] = (check(nums,n-1,tg-nums[n-1])+check(nums,n-1,tg+nums[n-1]));
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        dp = vector<unordered_map<int,int>>(nums.size()+1);
        return check(nums,nums.size(),target);
    }
};