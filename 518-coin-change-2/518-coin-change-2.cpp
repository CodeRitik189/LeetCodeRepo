class Solution {
public:
    vector<vector<int>>dp;
    int check(vector<int>& coins, int idx , int amt){
        if(amt==0){return 1;}
        if(idx==coins.size()){ return 0; }
        
        if(dp[idx][amt]!=-1){return dp[idx][amt];}
        
        int ans = check(coins,idx+1,amt);
        if(amt>=coins[idx])
           ans += check(coins,idx,amt-coins[idx]);
        return dp[idx][amt] = ans;
    }
    int change(int amt, vector<int>& coins) {
        int n = coins.size();
//         vector<int>dp(amt+1,INT_MAX);
        
//         dp[0] = 0;
        
//         for(int i = 1; i<= amt ;i++){
//             for(int j = 0; j< n; j++){
//                if(i>=coins[j] && dp[i-coins[j]]!=INT_MAX)
//                  dp[i] = min(dp[i],1+dp[i-coins[j]]);
//             }
//         }
        //return dp[amt]==INT_MAX ? -1 : dp[amt];
        dp = vector<vector<int>>(n,vector<int>(amt+1,-1));
        return check(coins,0,amt);
    }
};