class Solution {
public:
    vector<vector<int>>dp;
    int fees;
    int check(vector<int>& prices, int i, int buy){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){ return dp[i][buy]; }
        
        if(buy){
           return dp[i][buy] = max(prices[i]+check(prices,i+1,0)-fees,check(prices,i+1,1)); 
        }else{
           return dp[i][buy] = max(-prices[i]+check(prices,i+1,1),check(prices,i+1,0)); 
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        fees = fee;
        dp = vector<vector<int>>(n,vector<int>(2,-1));
        return check(prices,0,0);  
    }
};