class Solution {
public:
     vector<vector<vector<int>>>dp;
    int check(vector<int>& prices, int i, int buy, int k){
        if(i==prices.size()||k<0){
            return 0;
        }
        if(dp[i][buy][k]!=-1){ return dp[i][buy][k]; }
        
        if(buy){
           return dp[i][buy][k] = max(prices[i]+check(prices,i+1,0,k-1),check(prices,i+1,1,k)); 
        }else{
           return dp[i][buy][k] = max(-prices[i]+check(prices,i+1,1,k),check(prices,i+1,0,k)); 
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), k=2;
        
        dp = vector<vector<vector<int>>>(n,vector<vector<int>>(2,vector<int>(k,-1)));
        return check(prices,0,0,k-1);
    }
};