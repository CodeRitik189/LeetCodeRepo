class Solution {
public:
    vector<vector<double>>dp;
    int check(string& s, string& t, int i, int j){
        if(j==t.size()||i==s.size()){
            return (j==t.size());
        }
        if(dp[i][j] != -1){ return dp[i][j]; }
        int ans = 0;
        if(s[i]==t[j]){  
         ans += check(s,t,i+1,j+1);  
        }
        ans += check(s,t,i+1,j);
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
       int m = s.size(), n = t.size();
       dp = vector<vector<double>>(s.size()+1,vector<double>(t.size()+1,0));
      // return check(s,t,0,0);
      
      for(int i=0;i<=m;i++){
          dp[i][0] = 1;
      }
    
      for(int i=1;i<=m;i++){
          for(int j=0;j<=n;j++){
              dp[i][j] = dp[i-1][j];
              if(j>0&&s[i-1]==t[j-1]){
                  dp[i][j] += dp[i-1][j-1];
              }
          }
      }
        return (int)dp[m][n];
    }
};