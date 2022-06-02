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
        vector<int>dp(amt+1,0);
        
        for(int i=0; i<= amt; i++){ dp[i] = 0;}
        dp[0] =1;
        
        for(int i = 1; i<= n ;i++){
            vector<int>temp(amt+1,0);
            for(int j = 0; j<= amt; j++){
               temp[j] = dp[j];
               if(j>=coins[i-1] )
                 temp[j] += temp[j-coins[i-1]];
            }
            dp = temp;
        }
        return dp[amt];
    }
};