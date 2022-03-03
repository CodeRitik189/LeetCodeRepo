class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        if(nums.size()<3){return 0;}
        vector<vector<int>>dp(nums.size(),vector<int>(2001,1));
        for(int i=1;i<nums.size();i++){
            dp[i][nums[i]-nums[i-1]+1000] = dp[i-1][nums[i]-nums[i-1]+1000]+1;
            dp[i-1][nums[i]-nums[i-1]+1000] = 0;
        }
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<2001;j++){
                if(dp[i][j]>2){
                    ans += (((dp[i][j]-2)*(dp[i][j]-1))/2);
                }
            }
        }
       return ans;
    }
};