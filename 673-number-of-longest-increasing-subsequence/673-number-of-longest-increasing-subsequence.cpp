class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>ct(n,1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]  && dp[i] < dp[j] +1 ){
                    dp[i] = dp[j]+1;
                }
            }
            if(dp[i]>1){ ct[i] = 0;}
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]  && dp[i] == dp[j]+1){
                    ct[i] += ct[j];
                }
            }
        }
        int ans = 0, maxi = 1;
        for(int i=0; i<n; i++){
            if(maxi < dp[i]){
                maxi = dp[i];
                ans = ct[i];
            }else if(maxi == dp[i]){
                ans += ct[i];
            }
        }
        return ans;
    }
};