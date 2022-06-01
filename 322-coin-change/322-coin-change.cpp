class Solution {
public:
    unordered_map<int,int>dp;
    int check(vector<int>& coins,int amt){
        if(amt==0){return 0;}
        if(dp.find(amt)!=dp.end()){return dp[amt];}
        int ans = 1000000;
        for(int i=0;i<coins.size();i++){
            if(amt>=coins[i])
             ans = min(ans,check(coins,amt-coins[i]));
        }
        return dp[amt]=(ans==1000000?ans:1+ans);
    }
    int coinChange(vector<int>& coins, int amt) {
        // int ans = check(coins,amt);
        // return ans==1000000?-1:ans;
        int n = coins.size();
        vector<int>dp(amt+1,INT_MAX);
        
        dp[0] = 0;
        
        for(int i = 1; i<= amt ;i++){
            for(int j = 0; j< n; j++){
               if(i>=coins[j] && dp[i-coins[j]]!=INT_MAX)
                 dp[i] = min(dp[i],1+dp[i-coins[j]]);
            }
        }
        return dp[amt]==INT_MAX ? -1 : dp[amt];
    }
};