class Solution {
public:
    int paths(int m, int n, vector<vector<int>>& dp) {
        if(m==1||n==1){
            return 1;
        }
        if(dp[m][n]!= -1){
            return dp[m][n];
        }
        return dp[m][n] = paths(m-1,n,dp) + paths(m,n-1,dp);
    }
    int uniquePaths(int m, int n) {
      vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
       return paths(m,n,dp);
    }
};