class Solution {
public:
    bool canPartition(vector<int>& arr) {
        
    int n = arr.size(), k = 0;
    for(int i=0;i<n;i++){ k += arr[i]; }
    
    if(k%2 != 0)return false;
    k /=   2;
        
        
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));    
    for(int i = 0; i<= k; i++){
        dp[0][i] = 0;
    }
    
    dp[0][0] = 1;
    
    for(int i=1;i<=n;i++){
        for(int j = 0; j<=k ;j++){
            dp[i][j] = (dp[i-1][j]);
            if(j>=arr[i-1])
              dp[i][j] |= dp[i-1][j-arr[i-1]];
        }
    }
      return dp[n][k];
    }
};