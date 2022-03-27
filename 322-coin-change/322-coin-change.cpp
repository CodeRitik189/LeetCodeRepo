class Solution {
public:
    unordered_map<int,int>dp;
    int check(vector<int>& coins,int amt){
        if(amt<0){return 1000000;}
        if(amt==0){return 0;}
        if(dp.find(amt)!=dp.end()){return dp[amt];}
        int ans = 1000000;
        for(int i=0;i<coins.size();i++){
            ans = min(ans,check(coins,amt-coins[i]));
        }
        return dp[amt]=(ans==1000000?ans:1+ans);
    }
    int coinChange(vector<int>& coins, int amt) {
        int ans = check(coins,amt);
        return ans==1000000?-1:ans;
    }
};