class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        if(nums.size()<3){return 0;}
        vector<unordered_map<int,int>>dp(nums.size());
        for(int i=1;i<nums.size();i++){
            dp[i][nums[i]-nums[i-1]] = dp[i-1][nums[i]-nums[i-1]]+1;
            dp[i-1][nums[i]-nums[i-1]] = 0;
        }
        for(int i=0;i<dp.size();i++){
            for(auto j : dp[i]){
                if(j.second>=2){
                    ans += (((j.second)*(j.second-1))/2);
                }
            }
        }
       return ans;
    }
};