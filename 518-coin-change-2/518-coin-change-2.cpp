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
       // dp = vector<vector<int>>(n,vector<int>(amt+1,-1));
        //return check(coins,0,amt);
        vector<vector<int>>dp(n+1,vector<int>(amt+1,0));
        
        for(int i=0; i<= amt; i++){ dp[0][i] = 0;}
        for(int i=0; i<= n; i++){ dp[i][0] = 1;}
        
        for(int i = 1; i<= n ;i++){
            for(int j = 0; j<= amt; j++){
               dp[i][j] = dp[i-1][j];
               if(j>=coins[i-1] )
                 dp[i][j] += dp[i][j-coins[i-1]];
            }
        }
        return dp[n][amt];
    }
};