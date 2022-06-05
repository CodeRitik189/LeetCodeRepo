class Solution {
public:
// vector<vector<int>>dp;
//     int check(int n, int idx){
//         if(n==0){ return 0; }
//         if(idx<0||n<0){return 1e8; }
        
//         if(dp[n][idx]!=-1){ return dp[n][idx]; }
        
//         return dp[n][idx] = min(check(n,idx-1),1+check(n-ps[idx],idx));
//     }
    int numSquares(int n) {
        vector<int>ps;
        for(int i=1; i*i <= n ;i++){
            ps.push_back(i*i);
        } 
        vector<int>dp(n+1,1e8);
        dp[0] = 0;
        
        for(int i=1; i<= ps.size(); i++){
            vector<int>temp(n+1);
            for(int j=0; j<= n; j++){
                if(j==0){ temp[j] = 0; continue;}
                temp[j] = dp[j];
                if(j>=ps[i-1])temp[j] = min(temp[j],1+ temp[j-ps[i-1]]);
            }
            dp = temp;
        }
        return dp[n];
    }
};