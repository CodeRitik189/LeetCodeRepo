class Solution {
public:
    vector<int>ps;
    vector<vector<int>>dp;
    int check(int n, int idx){
        if(n==0){ return 0; }
        if(idx<0||n<0){return 1e8; }
        
        if(dp[n][idx]!=-1){ return dp[n][idx]; }
        
        return dp[n][idx] = min(check(n,idx-1),1+check(n-ps[idx],idx));
    }
    int numSquares(int n) {
        for(int i=1; i*i <= n ;i++){
            ps.push_back(i*i);
        } 
        dp = vector<vector<int>>(n+1,vector<int>(ps.size(),-1));
        return check(n,ps.size()-1);
    }
};